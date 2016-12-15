#pragma once
#include "Building.h"
class Farm :
	public Building
{
public:
	Farm ( int, int, std::string );
	virtual ~Farm ();

	int getID () override;
	void effect () override;
	void repair () override;
	void level_up() override;
	std::string getInfo () override;
	std::string getString () override;
	std::pair<int, int> getCoord () override;
	void setCoord ( int, int ) override;
private:
	int n_coins_;
};

