#include "World.h"


World::World (int w = MAX_WIDTH, int h = MAX_HEIGHT ) : world_width_(w), world_height_(h)
{}


World::~World ()
{}

std::shared_ptr<Entity> World::getEntity ( int id )
{
	for ( auto i = entities_.begin (); i != entities_.end (); ++i )
		if ( ( *i )->getID () == id )
			return *i;
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

const std::string & World::list_all_entities ()
{
	std::ostringstream oss;
	for ( auto i = entities_.begin (); i != entities_.end (); ++i )
		oss << ( *i )->getInfo ();

	return oss.str ();
}
