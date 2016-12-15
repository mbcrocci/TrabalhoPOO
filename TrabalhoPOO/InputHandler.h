#pragma once
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class InputHandler
{
public:
	InputHandler ();
	virtual ~InputHandler ();

	std::vector<std::string> split_string ( std::string );
	std::vector<std::string> handleInput ();
	std::vector<std::vector<std::string>> read_file ( std::string );
};

