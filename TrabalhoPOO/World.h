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
	World ();
	~World ();

	EntityPtr getEntity ( int );
	EntityPtr getFirstEntity ( int, int ) const;
	std::vector<std::vector<EntityPtr>> getBoard () const;


	std::pair<int, int> getWorldDim () const;
	void setWorldDim ( int, int );

	std::pair<int, int> getViewCoord () const;
	std::pair<int, int> getViewDim () const;
	void setViewCoord ( int, int );
	void setViewDim ( int, int );

	void autoResizeView ();
	void zoomIn ();
	void zoomOut ();
	void zoomOutN ( int );

	void setNCoins ( int );

	int getNColonies () const;
	void setNColonies ( int );
	bool colonyExists ( std::string );

	void makeProfile ( std::string );
	void addToProfile ( std::string, std::string );
	void removeProfile ( std::string );
	std::shared_ptr<Profile> findProfile ( std::string );

	void setColonyCoins ( std::string, int );

	void populate ();

	const std::string & list_all_entities ();

	std::string String ();

private:
	int world_width_, world_height_; // world dimensions
	int view_x_, view_y_; // view left corner coordinates
	int view_width_, view_height_;

	// Configs
	int n_coins_;
	int n_colonies_;
	std::vector<std::shared_ptr<Profile>> profiles_;
	std::vector<std::pair<int, int>> colony_positions_;
	std::vector<std::shared_ptr<Colony>> colonies_;

	std::vector<EntityPtr> entities_;
	std::vector<std::vector<EntityPtr>> board_;

};

