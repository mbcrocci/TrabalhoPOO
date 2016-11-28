#pragma once
#include "Building.h"
class Farm :
	public Building
{
public:
	Farm ();
	~Farm ();

	void effect () override;
	void repair () override;
	void level_up() override;

private:
	int n_coins_;
};

