#include "Farm.h"



Farm::Farm ()
{
	ID_ = 2; // TODO
	health_ = 20;
	defense_ = 10;
	level_ = 1;
	n_coins_ = 0;
}


Farm::~Farm ()
{}

int Farm::getID ()
{
	return ID_;
}

void Farm::effect ()
{
	// TODO: cost
	defense_++;
}

void Farm::repair()
{
	health_ = 20;
	defense_ = 10;
}

void Farm::level_up ()
{
	level_++;
	n_coins_++;
}

std::string Farm::getInfo()
{
	// TODO
	return "";
}

std::string Farm::getString()
{
	return "F";
}
