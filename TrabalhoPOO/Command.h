#pragma once
#include "World.h"

class Command
{
public:
	Command ();
	~Command ();

	virtual void execute (World&) = 0;
};

