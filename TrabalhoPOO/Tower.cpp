#include "Tower.h"



Tower::Tower ()
{
	ID_ = 3; // TODO
	health_ = 20;
	defense_ = 10;
	attack_ = 0;
	level_ = 1;
}


Tower::~Tower ()
{}

int Tower::getID ()
{
	return ID_;
}

void Tower::effect()
{
	//TODO: end
}

void Tower::repair()
{
	health_ = 20;
	defense_ = 10;
}

void Tower::level_up ()
{
	// TODO: cost
	defense_ += 2;
	attack_++;
	level_++;
}

std::string Tower::getInfo()
{
	//TODO
	return "";
}

std::string Tower::getString()
{
	return "T";
}
