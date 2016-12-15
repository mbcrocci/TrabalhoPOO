#pragma once
#include "Building.h"
class Castle :
	public Building
{
public:
	Castle ( int, int, std::string );
	virtual ~Castle ();

	void effect () override;
	void repair () override;
	void level_up () override;
	int getID () override;
	std::string getInfo () override;
	std::string  getString () override;
	std::pair<int, int> getCoord () override;
	void setCoord ( int, int ) override;
};

