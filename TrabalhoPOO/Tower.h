#pragma once
#include "Building.h"
class Tower : public Building
{
public:
	Tower ();
	virtual ~Tower ();

	int getID () override;
	void effect () override;
	void repair () override;
	void level_up () override;
	std::string getInfo () override;
	std::string getString () override;

private:
	int attack_;
};

