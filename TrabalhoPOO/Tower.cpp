#include "Tower.h"



Tower::Tower ()
{
	health_ = 20;
	defense_ = 10;
	attack_ = 0;
	level_ = 1;
}


Tower::~Tower ()
{}

void Tower::level_up ()
{
	// TODO: cost
	defense_ += 2;
	attack_++;
	level_++;
}
