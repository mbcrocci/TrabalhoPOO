#include "Castle.h"

Castle::Castle ( int x, int y, std::string c )
{
	ID_ = 1; // TODO: change
	health_ = 50;
	defense_ = 10;
	colony_ = c;
	x_ = x;
	y_ = y;
	colony_ = c;
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

void Castle::level_up()
{
	// do nothing
}

int Castle::getID ()
{
	return ID_;
}

std::string Castle::getInfo()
{
	//TODO
	std::ostringstream oss;
	oss << "Castle[" << colony_ << "] (" << x_ << ", " << y_ << "): " << health_ << ", " << defense_;
	return oss.str ();
}

std::string Castle::getString()
{
	return "C";
}

std::pair<int, int> Castle::getCoord()
{
	return std::make_pair ( x_, y_ );
}

void Castle::setCoord ( int x, int y )
{
	x_ = x;
	y_ = y;
}
