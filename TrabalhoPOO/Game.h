#pragma once
//#include <chrono>
//#include <thread>
#include <memory>
#include <vector>

#include "Consola.h"

#include "InputHandler.h"
#include "World.h"

#define MS_PER_FRAME 16

class Game
{
public:
	Game ();
	virtual ~Game ();

	int getTick () const;

	std::string list_configs() const;

	void loadInitFile ( std::string );

	void makeProfile ( std::string );
	void addToProfile ( std::string, std::string );
	void removeProfile ( std::string );
	std::shared_ptr<Profile> findProfile ( std::string );

	bool colonyExists ( std::string ) const;

	void init (); // run before starting game loop
				  // where config happens
	void run (); // main game loop

	void render ( World& ) const; // draws the game
	
private:
	int tick_;
	InputHandler input_handler_;
	std::vector<std::shared_ptr<Profile>> profiles_;

	// vector of colony letter and their starting coordinates
	std::map<std::string, std::pair<int, int>> colonies_map_;

//	World world_;

	int config_world_width_, config_world_heigth_;
	int config_num_coins_, config_num_colonies;
};

