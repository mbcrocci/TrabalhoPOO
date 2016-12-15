#include "Colony.h"



Colony::Colony ()
{}


Colony::~Colony ()
{}

std::string Colony::getName()
{
	return name;
}

void Colony::setNCoins(int n)
{
	n_coins_ = n;
}

void Colony::addBuilding(std::shared_ptr<Building> ptr ) 
{
	buildings_.push_back ( ptr );
}

void Colony::addBeeing(std::shared_ptr<Beeing> ptr)
{
	beeings_.push_back ( ptr );
}
