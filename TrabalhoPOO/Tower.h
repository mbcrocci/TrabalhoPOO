#pragma once
#include "Building.h"
class Tower : public Building
{
public:
	Tower ( int, int, std::string );
	virtual ~Tower ();

	int getID () override;
	void effect () override;
	void repair () override;
	void level_up () override;
	std::string getInfo () override;
	std::string getString () override;
	std::pair<int, int> getCoord () override;
	void setCoord ( int, int ) override;
private:
	int attack_;
};

