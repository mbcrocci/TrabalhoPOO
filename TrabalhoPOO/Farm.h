#pragma once
#include "Building.h"
class Farm :
	public Building
{
public:
	Farm ();
	virtual ~Farm ();

	int getID () override;
	void effect () override;
	void repair () override;
	void level_up() override;
	std::string getInfo () override;
	std::string getString () override;

private:
	int n_coins_;
};

