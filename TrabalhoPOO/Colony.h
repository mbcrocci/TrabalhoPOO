#pragma once
#include <vector>
#include <memory>
#include "Building.h"
#include "Monster.h"

class Colony
{
public:
	Colony ();
	~Colony ();

	std::string buildingList ();
	std::string monsterList ();
	std::string playerDetails ();

private:
	int n_moedas_;
	int color_; // maybe change it

	std::vector<std::shared_ptr<Building>> buildings_;
	std::vector<std::shared_ptr<Monster>> monsters_;

};

