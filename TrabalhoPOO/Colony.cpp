#include "Colony.h"

Colony::Colony ( std::string s ) : name_ ( s )
{
}

Colony::~Colony ()
{}

std::string Colony::getName()
{
	return name_;
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

std::shared_ptr<Building> Colony::getCastle() const
{
	for ( auto building : buildings_ )
		if ( building->getString () == "C" )
			return building;

	return nullptr;
}
