#pragma once
#include "Command.h"
class DimCommand :
	public Command
{
public:
	DimCommand ( World&, int, int );
	~DimCommand ();

	void execute () override;
private:
	World & world_;
	int width_, height_;
};

