#include "Game.h"



Game::Game ()
{}


Game::~Game ()
{}

void Game::init ()
{
	Command::configCommands ();
}

void Game::run ()
{
	while ( true )
	{
		std::chrono::time_point<std::chrono::system_clock> start, end;
		start = std::chrono::system_clock::now (); // gets current time

		get_user_input ();
		update ();
		render ();

		end = std::chrono::system_clock::now ();
		
		std::this_thread::sleep_for ( std::chrono::milliseconds ( start + MS_PER_FRAME - end ) );
	}
}
