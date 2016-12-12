#pragma once
#include <map>
#include "Command.h"
class InputHandler
{
public:
	InputHandler ();
	~InputHandler ();

private:
	std::map<std::string, Command> commands_;

};

