#include "Farm.h"



Farm::Farm ()
{
	health_ = 20;
	defense_ = 10;
	level_ = 1;
	n_coins_ = 0;
}


Farm::~Farm ()
{}

void Farm::effect ()
{
	// TODO: cost
	defense_++;
}

void Farm::level_up ()
{
	level_++;
	n_coins_++;
}
