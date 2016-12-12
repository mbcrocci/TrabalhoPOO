#pragma once
#include "Command.h"
class ListCommand :
	public Command
{
public:
	ListCommand (World&);
	~ListCommand ();

	void execute () override;

private:
	World world_;
};

