#include "World.h"
#include "Castle.h"
#include "consola.h"


World::World ( int ww, int wh, int nc,
	std::map < std::string, std::pair<int, int>> c_map,
	std::vector<std::shared_ptr<Profile>> profiles )
	: view_x_ ( 0 ), view_y_ ( 0 ),
	view_width_ ( MIN_WIDTH ), view_height_ ( MIN_HEIGHT ),
	colonies_map_ ( c_map ), profiles_ ( profiles )
{
	if ( ww < MIN_WIDTH ) world_width_ = MIN_WIDTH;
	else if ( ww > MAX_WIDTH ) world_width_ = MAX_WIDTH;
	else world_width_ = ww;

	if ( wh < MIN_HEIGHT ) world_height_ = MIN_HEIGHT;
	else if ( wh > MAX_HEIGHT ) world_height_ = MAX_HEIGHT;
	else world_height_ = wh;

	for ( auto const & c : colonies_map_ )
	{
		addColony ( c.first );

		auto colony = getColony ( c.first );
		if ( colony )
		{
			addBuilding ( c.second.first, c.second.second, "castelo", colony->getName () );
		}
	}
}


World::~World ()
{}

EntityPtr World::getFirstEntity( int x, int y ) const
{
	for ( auto entity : entities_ )
	{
		auto coord = entity->getCoord ();
		if ( coord.first == x && coord.second == y )
			return entity;
	}
	return nullptr;
}

std::pair<int, int> World::getWorldDim () const
{
	return std::pair<int, int> (world_width_, world_height_);
}

void World::setWorldDim ( int w, int h )
{
	world_width_ = w;
	world_height_ = h;
}

std::pair<int, int> World::getViewCoord () const
{
	return std::pair<int, int> (view_x_, view_y_);
}

std::pair<int, int> World::getViewDim () const
{
	return std::pair<int, int> (view_width_, view_height_);
}

std::pair<int, int> World::getViewLimits() const
{
	return std::pair<int, int> ( view_width_ + view_x_, view_height_ + view_y_ );
}

void World::setViewCoord ( int x , int y )
{
	view_x_ = x;
	view_y_ = y;
}

void World::setViewDim ( int vw, int  vh )
{
	view_width_ = vw;
	view_height_ = vh;
	//autoResizeView();
}

void World::autoResizeView ()
{
	if ( view_x_ + view_width_ > world_width_ )
		view_width_ = world_width_ - view_x_;

	if ( view_y_ + view_height_ > world_height_ )
		view_height_ = world_height_ - view_y_;
}

void World::zoomIn ()
{
	// impossible to zoom in
	if ( view_width_ == MIN_WIDTH || view_height_ == MIN_HEIGHT )
		return;
	
	view_width_--; view_height_--;
}

void World::zoomOut ()
{
	// impossible to zoom out
	if ( view_width_ == world_width_ || view_height_ == world_height_ )
		return;

	view_width_++; view_height_++;
}

void World::zoomOutN( int n )
{
	for ( auto i = 0; i < n; i++ )
		zoomOut ();
}

void World::addColony ( std::string c_name )
{
	if ( colonyExists ( c_name ) )
		return;

	Colony c ( c_name );
	colonies_.push_back ( std::make_shared<Colony> ( c ) );

}

bool World::colonyExists( std::string c_name )
{
	for ( auto colony : colonies_ )
		if ( colony->getName () == c_name )
			return true;

	return false;
}

void World::setColonyCoins( std::string c, int n )
{
	for ( auto colony : colonies_ )
		if ( colony->getName () == c )
			colony->setNCoins ( n );
}

std::shared_ptr<Colony> World::getColony(const std::string& cs)
{
	for ( auto colony : colonies_ )
		if ( colony->getName () == cs )
			return colony;

	return nullptr;
}

std::shared_ptr<Colony> World::getUserColony ()
{
	return colonies_[ 0 ];
}

void World::addBuilding ( int x, int y, std::string b_name, std::string c_name )
{
	auto colony = getColony ( c_name );
	if ( !colony )
		return;

	if ( b_name == "castelo" )
	{
		std::ostringstream oss;
		oss << "adding to world: " << "Castelo[" << c_name << "] (" << x << ", " << y << ")\n";
		Consola::debugPrint ( oss.str () );
		auto castle = std::make_shared<Castle>( x, y, c_name );
		entities_.push_back ( castle );
		colony->addBuilding ( castle );

	}
}

void World::makeBeeing ( std::string p_name )
{
	auto profile = findProfile ( p_name );
	if ( profile )
	{
		auto colony = getUserColony ();
		auto castle = colony->getCastle ();
		auto coord = castle->getCoord ();
		
		auto beeing = std::make_shared<Beeing> ( coord.first , coord.second, colony->getName (), profile );
		colony->addBeeing ( beeing );
		entities_.push_back ( beeing );
	}
}

std::shared_ptr<Profile> World::findProfile( std::string p_name )
{
	for ( auto p : profiles_ )
		if ( p->getName () == p_name )
			return p;

	return nullptr;
}

std::vector<EntityPtr> World::getAllBeeings(int x, int y)
{
	std::vector<EntityPtr> beeings;
	for ( auto entity : entities_ )
	{
		if ( entity->getString() == "B" )
		{
			auto coord = entity->getCoord ();
			if ( x == coord.first && y == coord.second )
				beeings.push_back ( entity );
		}
	}
	return beeings;
}

std::string World::list_all_entities ()
{
	std::ostringstream oss;
	for ( auto entity : entities_ )
		oss << entity->getInfo () << "\n";

	return oss.str ();
}

std::string World::list_config()
{
	std::ostringstream oss;
	oss << "World Config:\n"
		<< "\tWidth: " << world_width_ << "\n"
		<< "\tHeight: " << world_height_ << "\n"
		<< "\tView Coords: (" << view_x_ << ", " << view_y_ << ")\n"
		<< "\tView Width: " << view_width_ << "\n"
		<< "\tView Height: " << view_height_ << "\n";
	for ( auto const & colony : colonies_map_ )
		oss << "\t\t" << colony.first << ": (" << colony.second.first << "," << colony.second.second << ")\n";

	return oss.str ();
}