#pragma once
#include <memory>
#include <string>
class Entity
{
public:
	virtual int getID () = 0;
	virtual const std::string & getInfo () = 0;
	virtual std::string getString () = 0;


protected:
	int ID_;
};

typedef std::shared_ptr<Entity> EntityPtr;

