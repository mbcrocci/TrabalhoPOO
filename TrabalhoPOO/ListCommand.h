#pragma once
#include "Command.h"
class ListCommand :
	public Command
{
public:
	ListCommand ();
	~ListCommand ();

	void execute ( World& ) override;
};

