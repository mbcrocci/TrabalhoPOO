#include "Beeing.h"



Beeing::Beeing ()
{
	health_ = 0;
	power_ = 0;
	speed_ = 0;
	attack_ = 0;
	defense_ = 0;
}


Beeing::~Beeing ()
{}

std::string Beeing::getString()
{
	return "B";
}

void Beeing::set_profile(std::shared_ptr<Profile> p)
{
	profile_ = p;
}
