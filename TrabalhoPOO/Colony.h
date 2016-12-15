#pragma once
#include <vector>
#include <memory>
#include "Building.h"
#include "Beeing.h"

class Colony
{
public:
	Colony ( std::string );
	virtual ~Colony ();

	std::string getName ();

	void setNCoins ( int );

	void addBuilding ( std::shared_ptr<Building> );
	void addBeeing ( std::shared_ptr<Beeing> );

	std::shared_ptr<Building> getCastle () const;

	std::string buildingList ();
	std::string monsterList ();
	std::string playerDetails ();

private:
	std::string name_;
	int n_coins_;
	int color_; // maybe change it

	std::vector<std::shared_ptr<Building>> buildings_;
	std::vector<std::shared_ptr<Beeing>> beeings_;

};

