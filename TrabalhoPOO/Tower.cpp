#include "Tower.h"



Tower::Tower ( int x, int y, std::string c )
{
	ID_ = 3; // TODO
	health_ = 20;
	defense_ = 10;
	attack_ = 0;
	level_ = 1;
	x_ = x;
	y_ = y;
	colony_ = c;
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
	std::ostringstream oss;
	oss << "Tower (" << colony_ << "): " << health_ << ", " << defense_;
	return oss.str ();
}

std::string Tower::getString()
{
	return "T";
}

std::pair<int, int> Tower::getCoord()
{
	return std::make_pair ( x_, y_ );
}

void Tower::setCoord(int x , int y)
{
	x_ = x;
	y_ = y;
}
