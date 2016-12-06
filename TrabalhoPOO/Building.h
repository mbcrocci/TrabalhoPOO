#pragma once
#include "Entity.h"
class Building : public Entity
{
public:
	// TODO: change func name
	virtual void effect () = 0;

	virtual void repair () = 0;
	virtual void level_up () = 0;

protected:
	int health_;
	int defense_;
	int level_;
};

