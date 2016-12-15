#include "Game.h"

Game::Game () : tick_ ( 0 ), world_()
{}

Game::~Game ()
{}

int Game::getTick() const
{
	return tick_;
}

void Game::loadInitFile(std::string file_name)
{
	auto commands = input_handler_.read_file ( file_name );
	for ( auto command : commands )
		if ( command[ 0 ] == "dim" )
		{
			if ( command.size () != 3 )
				continue;

			auto w = std::stoi ( command[ 1 ] );
			auto h = std::stoi ( command[ 2 ] );
			//TODO: validade  
			world_->setWorldDim ( w, h );
		}
		else if ( command[ 0 ] == "moedas" )
		{
			if ( command.size () != 2 )
				continue;

			auto n = std::stoi ( command[ 1 ] );
			//TODO: validade  

			world_->setNCoins ( n );
		}
		else if ( command[ 0 ] == "oponentes" )
		{
			if ( command.size () != 2 )
				continue;

			auto n = std::stoi ( command[ 1 ] );
			//TODO: validade  

			world_->setNColonies ( n );
		}
		else if ( command[ 0 ] == "castelo" )
		{
			if ( command.size () != 4 || world_->getNColonies () <= 0 )
				continue;

			//TODO: validade colony
			if ( world_->colonyExists ( command[ 1 ] ) )
				continue;

			auto l = std::stoi ( command[ 2 ] );
			auto c = std::stoi ( command[ 3 ] );
			//TODO: validade  

			// TODO: END!!

		}
		else if ( command[ 0 ] == "mkperfil" )
		{
			if ( command.size () != 2 )
				continue;

			//TODO: validate
			world_->makeProfile ( command[ 2 ] );
		}
		else if ( command[ 0 ] == "addperfil" )
		{
			if ( command.size () != 3 )
				continue;

			// TODO: validate
			world_->addToProfile ( command[ 1 ], command[ 2 ] );
		}
		else if ( command[ 0 ] == "subperfil" )
		{
			if ( command.size () != 3 )
				continue;

			// TODO: validate
			world_->addToProfile ( command[ 1 ], command[ 2 ] );
		}
		else if ( command[ 0 ] == "rmperfil" )
		{
			if ( command.size () != 2 )
				continue;

			world_->removeProfile ( command[ 1 ] );
		}
		else if ( command[ 0 ] == "load" )
		{
			if ( command.size () != 2 )
				continue;

			this->loadInitFile ( command[ 1 ] );
		}
		else if ( command[ 0 ] == "inicio" )
		{
			break;
		}
}

void Game::init ()
{
	while ( true )
	{
		auto command = input_handler_.handleInput ();
		std::ostringstream oss;
		for ( auto cmd : command )
			oss << "[" << cmd << "]";
		std::cout << oss.str ();

		if (command[0] == "dim" )
		{
			if ( command.size() != 3 )
				continue;

			auto w = std::stoi ( command[ 1 ] );
			auto h = std::stoi ( command[ 2 ] );
			//TODO: validade  
			world_->setWorldDim ( w, h );
			std::cout << "command success!\n";
		}
		else if (command[0] == "moedas" )
		{
			if ( command.size () != 2 )
				continue;

			auto n = std::stoi ( command[ 1 ] );
			//TODO: validade  

			world_->setNCoins ( n );
		} 
		else if (command[0] == "oponentes" )
		{
			if ( command.size () != 2 )
				continue;

			auto n = std::stoi ( command[ 1 ] );
			//TODO: validade  

			world_->setNColonies ( n );
			std::cout << "command success!\n";
		}
		else if (command[0] == "castelo" )
		{
			if ( command.size () != 4 || world_->getNColonies() <= 0)
				continue;

			//TODO: validade colony
			if ( world_->colonyExists ( command[ 1 ] ) )
				continue;

			auto l = std::stoi ( command[ 2 ] );
			auto c = std::stoi ( command[ 3 ] );
			//TODO: validade  

			// TODO: END!!
			std::cout << "command success!\n";
		}
		else if ( command[ 0 ] == "mkperfil" )
		{
			if ( command.size () != 2 )
				continue;

			//TODO: validate
			world_->makeProfile ( command[ 2 ] );
			std::cout << "command success!\n";
		}
		else if ( command[ 0 ] == "addperfil" )
		{
			if ( command.size () != 3 )
				continue;

			// TODO: validate
			world_->addToProfile ( command[ 1 ], command[ 2 ] );
			std::cout << "command success!\n";
		}
		else if ( command[ 0 ] == "subperfil" )
		{
			if ( command.size () != 3 )
				continue;

			// TODO: validate
			world_->addToProfile ( command[ 1 ], command[ 2 ] );
			std::cout << "command success!\n";
		}
		else if ( command[ 0 ] == "rmperfil" )
		{
			if ( command.size () != 2 )
				continue;

			world_->removeProfile ( command[ 1 ] );
		}
		else if ( command[ 0 ] == "load" )
		{
			if ( command.size () != 2 )
				continue;

			this->loadInitFile ( command[ 1 ] );
		}
		else if ( command[ 0 ] == "inicio" )
		{
			std::cout << "command success!\n";
			break;
		}
	}
}

void Game::run ()
{
	while ( true )
	{
		//std::chrono::time_point<std::chrono::system_clock> start, end;
		//start = std::chrono::system_clock::now (); // gets current time

		// Get input
		auto command = input_handler_.handleInput ();
		if ( command[0] == "foco" )
		{
			if ( command.size () != 3 )
				continue;

			auto w = std::stoi ( command[ 1 ] );
			auto h = std::stoi ( command[ 2 ] );
			//TODO: validate
			world_->setViewDim ( w, h );
		}
		else if ( command[ 0 ] == "zoomout" )
		{
			if ( command.size () != 2 )
				continue;

			auto n = std::stoi ( command[ 1 ] );
			//TODO: validate
			world_->zoomOutN ( n );
		}
		else if ( command[ 0 ] == "setmoedas" )
		{
			if ( command.size () != 3 )
				continue;

			auto n = std::stoi ( command[ 2 ] );
			
			world_->setColonyCoins ( command[ 1 ], n );
		}
		else if ( command[ 0 ] == "build" )
		{
		}
		else if ( command[ 0 ] == "list" )
		{
			continue;
		}
		else if ( command[ 0 ] == "listp" )
		{
			continue;
		}
		else if ( command[ 0 ] == "listallp" )
		{
			continue;
		}
		else if ( command[ 0 ] == "mkbuild" )
		{
			continue;
		}
		else if ( command[ 0 ] == "repair" )
		{
			continue;
		}
		else if ( command[ 0 ] == "upgrade" )
		{
			continue;
		}
		else if ( command[ 0 ] == "sell" )
		{
			continue;
		}
		else if ( command[ 0 ] == "ser" )
		{
			continue;
		}
		else if ( command[ 0 ] == "next" )
		{
			// go to next iteration = next tick
			continue;
		}
		else if ( command[ 0 ] == "nextn" )
		{
			if ( command.size() != 2 )
				continue;

			auto n = std::stoi ( command[ 1 ] );
			tick_ += n - 1; // -1 because it will always increase after render()
		}
		else if ( command[ 0 ] == "ataca" )
		{
			continue;
		}
		else if ( command[ 0 ] == "recolhe" )
		{
			continue;
		}
		else if ( command[ 0 ] == "fim" )
		{
			break;
		}
		else if ( command[ 0 ] == "save" )
		{
			continue;
		}
		else if ( command[ 0 ] == "restore" )
		{
			continue;
		}
		else if ( command[ 0 ] == "erase" )
		{
			continue;
		}
		else if ( command[ 0 ] == "load" )
		{
			continue;
		}

		//update ();
		render ();

		tick_++;

		//end = std::chrono::system_clock::now ();
		//std::this_thread::sleep_for ( std::chrono::milliseconds ( start + MS_PER_FRAME - end ) );
	}
}

void Game::render()
{
	//Consola::clrscr ();

	auto view_coord = world_->getViewCoord ();
	auto view_dims = world_->getViewDim ();
	auto board = world_->getBoard ();

	for ( auto y = view_coord.second; y < view_dims.second; y++ )
	{
		for ( auto x = view_coord.first; x < view_dims.first; x++ )
		{
			std::string chr;
			auto entity = world_->getFirstEntity ( x, y );
			if ( entity )
			{
	//			Consola::setTextColor ( Consola::VERDE );
				std::cout << board[ y ][ x ]->getString ();
	//			Consola::setTextColor ( Consola::BRANCO );
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}

}
