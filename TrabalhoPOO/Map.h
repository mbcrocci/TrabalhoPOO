#pragma once
#include <vector>
#include <memory>
#include "Building.h"

class Map
{
public:
	Map ();
	~Map ();

	std::shared_ptr<Building> getBuilding

private:
	std::vector<std::shared_ptr<Building>> buildings_;
};

