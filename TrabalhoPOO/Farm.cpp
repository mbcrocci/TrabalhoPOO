#include "Farm.h"

Farm::Farm ( int x, int y, std::string c )
{
	ID_ = 2; // TODO
	health_ = 20;
	defense_ = 10;
	level_ = 1;
	n_coins_ = 0;
	x_ = x;
	y_ = y;
	colony_ = c;
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
	std::ostringstream oss;
	oss << "Farm (" << colony_ << "): " << health_ << ", " << defense_;
	return oss.str ();
}

std::string Farm::getString()
{
	return "F";
}

std::pair<int, int> Farm::getCoord()
{
	return std::make_pair ( x_, y_ );
}

void Farm::setCoord ( int x, int y )
{
	x_ = x;
	y_ = y;
}
