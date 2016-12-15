#include "Castle.h"

Castle::Castle ()
{
	ID_ = 1; // TODO: change
	health_ = 50;
	defense_ = 10;
}


Castle::~Castle ()
{}

void Castle::effect()
{
	//TODO
}

void Castle::repair()
{
	health_ = 50;
	defense_ = 10;
}

int Castle::getID ()
{
	return ID_;
}

std::string Castle::getInfo()
{
	//TODO
	return "";
}

std::string Castle::getString()
{
	return "C";
}
