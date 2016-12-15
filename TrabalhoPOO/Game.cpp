#include "Game.h"

Game::Game () : tick_ ( 0 )
{ }

Game::~Game ()
{}

int Game::getTick() const
{
	return tick_;
}

std::string Game::list_configs () const
{
	std::ostringstream oss;
	oss << "Config:\n"
		<< "\tWidth: " << config_world_width_ << "\n"
		<< "\tHeight: " << config_world_heigth_ << "\n"
		<< "\tNCoins: " << config_num_coins_ << "\n"
		<< "\tNCOlonies: " << config_num_colonies << "\n"
		<< "\tColonies:\n";

	for ( auto const & colony : colonies_map_ )
		oss << "\t\t" << colony.first << ": (" << colony.second.first << "," << colony.second.second << ")\n";

	// TODO: profiles

	return oss.str ();
}

void Game::makeProfile ( std::string p_name )
{
	bool found = false;
	for ( auto profile : profiles_ )
		if ( profile->getName () != p_name )
			found = true;

	if ( !found )
		profiles_.push_back ( std::make_shared<Profile> ( p_name ) );
}

void Game::addToProfile ( std::string p_name, std::string trait )
{
	auto profile = findProfile ( p_name );
	if ( profile )
	{
		profile->addTrait ( trait );
	}
}

void Game::removeProfile ( std::string p_name )
{
	int pos;
	for ( unsigned int i = 0; i < profiles_.size (); i++ )
		if ( profiles_[ i ]->getName () == p_name )
			pos = i;

	profiles_.erase ( profiles_.begin () + pos, profiles_.end () );
}

std::shared_ptr<Profile> Game::findProfile ( std::string s )
{
	for ( auto p : profiles_ )
		if ( p->getName () == s )
			return p;

	return nullptr;
}

bool Game::colonyExists ( std::string c_name ) const
{
	if ( colonies_map_.find ( c_name ) != colonies_map_.end () )
		return true;

	return false;
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
			config_world_width_ = w;
			config_world_heigth_ = h;
		}
		else if ( command[ 0 ] == "moedas" )
		{
			if ( command.size () != 2 )
				continue;

			auto n = std::stoi ( command[ 1 ] );
			//TODO: validade  

			config_num_coins_ = n;
		}
		else if ( command[ 0 ] == "oponentes" )
		{
			if ( command.size () != 2 )
				continue;

			auto n = std::stoi ( command[ 1 ] );
			//TODO: validade  

			config_num_colonies = n;
		}
		else if ( command[ 0 ] == "castelo" )
		{
			if ( command.size () != 4 || config_num_colonies <= 0 )
				continue;

			//TODO: validade colony
			if ( colonyExists ( command[ 1 ] ) )
				continue;

			auto l = std::stoi ( command[ 2 ] );
			auto c = std::stoi ( command[ 3 ] );
			//TODO: validade  

			colonies_map_[ command[ 1 ] ] = std::make_pair ( l, c );
		}
		else if ( command[ 0 ] == "mkperfil" )
		{
			if ( command.size () != 2 )
				continue;

			//TODO: validate
			makeProfile ( command[ 1 ] );
		}
		else if ( command[ 0 ] == "addperfil" )
		{
			if ( command.size () != 3 )
				continue;

			// TODO: validate
			addToProfile ( command[ 1 ], command[ 2 ] );
		}
		else if ( command[ 0 ] == "subperfil" )
		{
			if ( command.size () != 3 )
				continue;

			// TODO: validate
			addToProfile ( command[ 1 ], command[ 2 ] );
		}
		else if ( command[ 0 ] == "rmperfil" )
		{
			if ( command.size () != 2 )
				continue;

			removeProfile ( command[ 1 ] );
		}
		else if ( command[ 0 ] == "load" )
		{
			if ( command.size () != 2 )
				continue;

			loadInitFile ( command[ 1 ] );
		}
		else if ( command[ 0 ] == "inicio" )
		{
			// doesnt do anything, use it in init loop to start the game
			break;
		}
}

void Game::init ()
{
	while ( true )
	{
		auto command = input_handler_.handleInput ();

		if ( command[ 0 ] == "dim" )
		{
			if ( command.size () != 3 )
				continue;

			auto w = std::stoi ( command[ 1 ] );
			auto h = std::stoi ( command[ 2 ] );
			//TODO: validade  
			config_world_width_ = w;
			config_world_heigth_ = h;
		}
		else if ( command[ 0 ] == "moedas" )
		{
			if ( command.size () != 2 )
				continue;

			auto n = std::stoi ( command[ 1 ] );
			//TODO: validade  

			config_num_coins_ = n;
		}
		else if ( command[ 0 ] == "oponentes" )
		{
			if ( command.size () != 2 )
				continue;

			auto n = std::stoi ( command[ 1 ] );
			//TODO: validade  

			config_num_colonies = n;
		}
		else if ( command[ 0 ] == "castelo" )
		{
			if ( command.size () != 4 || config_num_colonies <= 0 )
				continue;

			//TODO: validade colony
			if ( colonyExists ( command[ 1 ] ) )
				continue;

			auto l = std::stoi ( command[ 2 ] );
			auto c = std::stoi ( command[ 3 ] );
			//TODO: validade  

			colonies_map_[ command[ 1 ] ] = std::make_pair ( l, c );
		}
		else if ( command[ 0 ] == "mkperfil" )
		{
			if ( command.size () != 2 )
				continue;

			//TODO: validate
			makeProfile ( command[ 1 ] );
		}
		else if ( command[ 0 ] == "addperfil" )
		{
			if ( command.size () != 3 )
				continue;

			// TODO: validate
			addToProfile ( command[ 1 ], command[ 2 ] );
		}
		else if ( command[ 0 ] == "subperfil" )
		{
			if ( command.size () != 3 )
				continue;

			// TODO: validate
			addToProfile ( command[ 1 ], command[ 2 ] );
		}
		else if ( command[ 0 ] == "rmperfil" )
		{
			if ( command.size () != 2 )
				continue;

			removeProfile ( command[ 1 ] );
		}
		else if ( command[ 0 ] == "load" )
		{
			if ( command.size () != 2 )
				continue;

			loadInitFile ( command[ 1 ] );
		}
		else if ( command[ 0 ] == "inicio" )
		{
			break;
		}
		else
		{
			std::cout << "Command invalid!\n";
		}
	}
}

void Game::run ()
{
	Consola::clrscr ();

	World world_( 
		config_world_width_, config_world_heigth_,
		config_num_coins_, colonies_map_, profiles_
	);

	// show once before startin game loop
	render ( world_ );
	while ( true )
	{
		//std::chrono::time_point<std::chrono::system_clock> start, end;
		//start = std::chrono::system_clock::now (); // gets current time

		Consola::debugPrint ( "listing all entities" );
		Consola::debugPrint ( world_.list_all_entities () );

		// Get input
		auto command = input_handler_.handleInput ();
		if ( command[0] == "foco" )
		{
			if ( command.size () != 3 )
				continue;

			auto w = std::stoi ( command[ 1 ] );
			auto h = std::stoi ( command[ 2 ] );
			//TODO: validate
			world_.setViewCoord ( w, h );
		}
		else if ( command[ 0 ] == "zoomout" )
		{
			if ( command.size () != 2 )
				continue;

			auto n = std::stoi ( command[ 1 ] );
			//TODO: validate
			world_.zoomOutN ( n );
		}
		else if ( command[ 0 ] == "setmoedas" )
		{
			if ( command.size () != 3 )
				continue;

			auto n = std::stoi ( command[ 2 ] );
			
			world_.setColonyCoins ( command[ 1 ], n );
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
			if ( command.size() != 3 )
				continue;

			auto num = std::stoi ( command[ 1 ] );

			for ( auto i = 0; i < num; i++ )
				world_.makeBeeing ( command[ 2 ] );
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
			// TODO: Do this right!
			auto coord = world_.getUserColony ()->getCastle ()->getCoord ();
			auto beeings = world_.getAllBeeings ( coord.first, coord.second );

			for ( auto beeing : beeings )
				beeing->setCoord ( coord.first + 2, coord.second + 3 );
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
		else
		{
			std::cout << "Command invalid!\n";
		}

		//update ();
		render (world_);

		tick_++;

		//end = std::chrono::system_clock::now ();
		//std::this_thread::sleep_for ( std::chrono::milliseconds ( start + MS_PER_FRAME - end ) );
	}
}

void Game::render( World& world_) const
{
	Consola::clrscr ();
	//Consola::debugPrint ( list_configs () );
	//Consola::debugPrint ( world_.list_config () );

	auto view_coord = world_.getViewCoord ();
	auto view_limit = world_.getViewLimits ();

	for ( auto y = view_coord.second; y < view_limit.second; y++ )
	{
		for ( auto x = view_coord.first; x < view_limit.first; x++ )
		{
			std::string chr;
			auto entity = world_.getFirstEntity ( x, y );
			if ( entity )
			{
				Consola::setTextColor ( Consola::VERDE );
				std::cout << entity->getString ();
				Consola::setTextColor ( Consola::BRANCO );
			}
			else
			{
				std::cout << "_";
			}
		}
		std::cout << "\n";
	}
}
