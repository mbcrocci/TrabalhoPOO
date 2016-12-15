#include "InputHandler.h"
#include <string>


InputHandler::InputHandler ()
{
}


InputHandler::~InputHandler ()
{}

std::vector<std::string> InputHandler::split_string ( std::string s )
{
	std::vector<std::string> words;
	std::string delim = " ";
	auto start = 0U;
	auto end = s.find ( delim );

	while ( end != std::string::npos )
	{
		words.push_back ( s.substr ( start, end - start ) );
		start = end + delim.length ();
		end = s.find ( delim, start );
	}

	return words;
}

std::vector<std::string> InputHandler::handleInput ()
{
	std::string command_string;
	std::cout << "Command: ";
	std::getline ( std::cin, command_string );

	return split_string ( command_string );
}
