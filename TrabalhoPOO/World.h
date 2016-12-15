#pragma once
#include <vector>
#include <memory>
#include <sstream>
#include "Entity.h"
#include "Colony.h"
#include "Profile.h"

#define MIN_WIDTH 40
#define MAX_WIDTH 100

#define MIN_HEIGHT 20
#define MAX_HEIGHT 100


class World
{
public:
	World ( int width, int height, int coins,
		std::map < std::string, std::pair<int, int>> colonies_map,
		std::vector<std::shared_ptr<Profile>> profiles );

	virtual ~World ();

	std::pair<int, int> getWorldDim () const;
	void setWorldDim ( int, int );

	std::pair<int, int> getViewCoord () const;
	std::pair<int, int> getViewDim () const;
	std::pair<int, int> getViewLimits () const;
	void setViewCoord ( int, int );
	void setViewDim ( int, int );

	void autoResizeView ();
	void zoomIn ();
	void zoomOut ();
	void zoomOutN ( int );

	void addColony ( std::string );
	bool colonyExists ( std::string );
	void setColonyCoins ( std::string, int );

	std::shared_ptr<Colony> getColony(const std::string& cs);
	std::shared_ptr<Colony> getUserColony ();

	//EntityPtr getEntity ( int );
	EntityPtr getFirstEntity ( int, int ) const;

	void addBuilding ( int, int, std::string, std::string );
	void makeBeeing ( std::string );

	std::shared_ptr<Profile> findProfile ( std::string );

	std::vector<EntityPtr> getAllBeeings ( int x, int y );

	std::string list_all_entities ();
	std::string list_config();

private:
	int world_width_, world_height_; // world dimensions
	int view_x_, view_y_; // view left corner coordinates
	int view_width_, view_height_;

	std::map<std::string, std::pair<int, int>> colonies_map_;

	std::vector<std::shared_ptr<Colony>> colonies_;

	std::vector<EntityPtr> entities_;
	std::vector<std::shared_ptr<Profile>> profiles_;

};

