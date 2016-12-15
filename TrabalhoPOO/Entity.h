#pragma once
#include <memory>
#include <string>
#include <sstream>
class Entity
{
public:
	virtual int getID () = 0;
	virtual  std::string getInfo () = 0;
	virtual std::string getString () = 0;
	virtual std::pair<int, int> getCoord () = 0;
	virtual void setCoord ( int, int ) = 0;

protected:
	int ID_;
	int x_, y_;
	std::string colony_;
};

typedef std::shared_ptr<Entity> EntityPtr;

