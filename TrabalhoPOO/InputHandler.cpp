#include "InputHandler.h"

InputHandler::InputHandler ()
{
}


InputHandler::~InputHandler ()
{}

std::vector<std::string> InputHandler::split_string ( std::string s )
{
	std::vector<std::string> words;
	std::string delim = " ";
	size_t pos = 0;
	std::string token;
	while ( ( pos = s.find ( delim ) ) != std::string::npos )
	{
		token = s.substr ( 0, pos );
		words.push_back ( token );
		s.erase ( 0, pos + delim.length () );
	}
	words.push_back ( s );

	return words;
}

std::vector<std::string> InputHandler::handleInput ()
{
	std::string command_string;
	std::cout << "Command: ";
	std::getline ( std::cin, command_string );

	return split_string ( command_string );
}

std::vector<std::vector<std::string>> InputHandler::read_file( std::string file_name )
{
	std::vector<std::vector<std::string>> commands;
	std::ifstream file ( file_name );
	std::string line;
	while ( std::getline ( file, line ) )
	{
		auto command = split_string ( line );
		commands.push_back ( command );
	}
	return commands;
}
