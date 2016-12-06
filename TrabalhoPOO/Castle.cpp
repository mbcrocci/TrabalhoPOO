#include "Castle.h"

Castle::Castle ()
{
	ID_ = 1; // TODO: change
	health_ = 50;
	defense_ = 10;
}


Castle::~Castle ()
{}

int Castle::getID ()
{
	return ID_;
}