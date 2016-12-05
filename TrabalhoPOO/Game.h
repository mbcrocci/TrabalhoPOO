#pragma once
#include <chrono>
#include <thread>

#include "Command.h"
#include "Colony.h"
#include "Map.h"

#define MS_PER_FRAME 16

class Game
{
public:
	Game ();
	~Game ();

	void init (); // run before starting game loop
				  // where config happens
	void run (); // main game loop

	void get_user_input (); // get user input
	void update (); // advance 
	void render (); // draws the game
	
private:
	Map map_;
	Command command_;
	Colony colony_;

};

