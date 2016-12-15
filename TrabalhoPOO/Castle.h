#pragma once
#include "Building.h"
class Castle :
	public Building
{
public:
	Castle ();
	~Castle ();

	void effect () override;
	void repair () override;
	int getID () override;
	std::string  getString () override;
};

