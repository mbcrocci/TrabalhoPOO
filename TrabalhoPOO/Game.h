#pragma once
//#include <chrono>
//#include <thread>
#include <memory>
#include <vector>

//#include "Consola.h"

#include "InputHandler.h"
#include "World.h"

#define MS_PER_FRAME 16

class Game
{
public:
	Game ();
	virtual ~Game ();

	int getTick () const;

	void loadInitFile ( std::string );

	void init (); // run before starting game loop
				  // where config happens
	void run (); // main game loop

	void render (); // draws the game
	
private:
	int tick_;
	InputHandler input_handler_;
	std::shared_ptr<World> world_;
};

