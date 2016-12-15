#include "World.h"


World::World ()
	: world_width_(MAX_WIDTH), world_height_(MAX_HEIGHT),
	  view_width_ ( MIN_WIDTH ), view_height_ ( MIN_HEIGHT ),
	  view_x_(0), view_y_(0)
{
}


World::~World ()
{}

EntityPtr World::getFirstEntity( int x, int y ) const
{
	return board_[ y ][ x ];
}

std::vector<std::vector<EntityPtr>> World::getBoard () const
{
	return board_;
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

void World::setViewCoord ( int x , int y )
{
	view_x_ = x;
	view_y_ = y;
}

void World::setViewDim ( int vw, int  vh )
{
	view_width_ = vw;
	view_height_ = vh;
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

void World::setNCoins( int n )
{
	n_coins_ = n;
}

int World::getNColonies () const
{
	return n_colonies_;
}

void World::setNColonies ( int n )
{
	n_colonies_ = n;
}

bool World::colonyExists( std::string c_name )
{
	for ( auto colony : colonies_ )
		if ( colony->getName () == c_name )
			return true;

	return false;
}

void World::makeProfile( std::string p_name )
{
	bool found = false;
	for ( auto profile : profiles_ )
		if ( profile->getName () != p_name )
			found = true;

	if ( !found )
		profiles_.push_back ( std::make_shared<Profile> ( p_name ) );
}

void World::addToProfile( std::string p_name, std::string trait )
{
	auto profile = findProfile ( p_name );
	if ( profile )
	{
		profile->addTrait ( trait );
	}
}

void World::removeProfile( std::string p_name )
{
	int pos;
	for ( unsigned int i = 0; i < profiles_.size (); i++ )
		if ( profiles_[ i ]->getName () == p_name )
			pos = i;

	profiles_.erase ( profiles_.begin () + pos, profiles_.end () );
}

std::shared_ptr<Profile> World::findProfile( std::string s )
{
	for ( auto p : profiles_ )
		if ( p->getName () == s )
			return p;

	return nullptr;
}

void World::setColonyCoins( std::string c, int n )
{
	for ( auto colony : colonies_ )
		if ( colony->getName () == c )
			colony->setNCoins ( n );
}

void World::populate()
{
	for ( auto i = 0; i < world_height_; i++ )
		for ( auto j = 0; j < world_width_; j++ )
		{
			board_[ i ][ j ] = nullptr;
		}
	// 
}

std::string World::list_all_entities ()
{
	std::ostringstream oss;
	for ( auto i = entities_.begin (); i != entities_.end (); ++i )
		oss << ( *i )->getInfo ();

	return oss.str ();
}

std::string World::String()
{
	std::ostringstream oss;
	for ( auto y = 0; y < world_height_; y++ )
	{
		for ( auto x = 0; x < world_width_; x++ )
		{
			oss << board_[ y ][ x ]->getString ();
		}
		oss << "\n";
	}
	return oss.str ();
}
