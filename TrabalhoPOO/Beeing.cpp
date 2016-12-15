#include "Beeing.h"

Beeing::Beeing(int x, int y , std::string c_name, std::shared_ptr<Profile> p)
{
	health_ = 0;
	power_ = 0;
	speed_ = 0;
	attack_ = 0;
	defense_ = 0;
	x_ = x;
	y_ = y;
	colony_ = c_name;
	profile_ = p;
}

Beeing::~Beeing ()
{}

int Beeing::getID()
{
	return 1; // TODO
}

std::string Beeing::getInfo()
{
	std::ostringstream oss;
	oss << "Beeing (" << colony_ << "): " << health_ << ", " << defense_;
	return oss.str ();
}

std::string Beeing::getString ()
{
	return "B";
}

std::pair<int, int> Beeing::getCoord ()
{
	return std::make_pair ( x_, y_ );
}

void Beeing::setCoord ( int x, int y )
{
	x_ = x;
	y_ = y;
}

void Beeing::set_profile(std::shared_ptr<Profile> p)
{
	profile_ = p;
}
