#pragma once
#include <vector>
#include <memory>
#include <sstream>
#include "Entity.h"

#define MIN_WIDTH 40
#define MAX_WIDTH 100

#define MIN_HEIGHT 20
#define MAX_HEIGHT 100


class World
{
public:
	World ( int, int );
	std::shared_ptr<Entity> getEntity ( int );

	std::pair<int, int> getViewCoord () const;
	std::pair<int, int> getViewDim () const;
	void setViewCoord ( int, int );
	void setViewDim ( int, int );
	void zoomIn ();
	void zoomOut ();

	const std::string & list_all_entities ();

private:
	int world_width_, world_height_; // world dimensions

	int view_x_, view_y_; // view left corner coordinates
	int view_width_, view_height_;

	std::vector<std::shared_ptr<Entity>> entities_;
};

