#pragma once
//#include <chrono>
//#include <thread>
#include <memory>

#include "Consola.h"

#include "InputHandler.h"
#include "World.h"

#define MS_PER_FRAME 16

class Game
{
public:
	Game ();
	~Game ();

	int getTick () const;

	void loadInitFile ( std::string );

	void executeCommand ( std::vector<std::string> );

	void init (); // run before starting game loop
				  // where config happens
	void run (); // main game loop

	void get_user_input (); // get user input
	void update (); // advance 
	void render (); // draws the game
	
private:
	int tick_;
	InputHandler input_handler_;
	std::shared_ptr<World> world_ = nullptr;

	std::map<int, int> colony_colors_ = {
		{ 0, Consola::VERDE_CLARO },
		{ 1, Consola::VERMELHO_CLARO },
		{ 2, Consola::AZUL_CLARO },
	};

};

