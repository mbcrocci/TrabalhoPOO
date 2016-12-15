#pragma once
#include <map>
#include <iostream>
#include <vector>
class InputHandler
{
public:
	InputHandler ();
	~InputHandler ();

	bool isInitCommand ();
	bool isPlayCommand ();

	std::vector<std::string> split_string ( std::string );
	std::vector<std::string> handleInput ();
	std::vector<std::vector<std::string>> read_file ( std::string );
};

