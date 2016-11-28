#pragma once
#include "Building.h"
class Tower : public Building
{
public:
	Tower ();
	~Tower ();

	void effect () override;
	void repair () override;
	void level_up () override;

private:
	int attack_;
};

