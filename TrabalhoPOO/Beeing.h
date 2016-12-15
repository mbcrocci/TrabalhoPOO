#pragma once
#include <memory>
#include "Profile.h"
#include "Entity.h"

class Beeing : public Entity
{
public:
	Beeing ( int x, int y, std::string colony, std::shared_ptr<Profile> );
	virtual ~Beeing ();

	int getID () override;
	std::string getInfo () override;
	std::string getString () override;

	std::pair<int, int> getCoord () override;

	void setCoord ( int, int ) override;

	void set_profile ( std::shared_ptr<Profile> );

private:
	int health_ = 10;
	int power_ = 10;
	int speed_;
	int attack_;
	int defense_;

	std::shared_ptr<Profile> profile_;;
};