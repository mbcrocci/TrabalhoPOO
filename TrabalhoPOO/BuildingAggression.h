#pragma once
#include "Trait.h"
class BuildingAggression :
	public Trait
{
public:
	BuildingAggression ();
	virtual ~BuildingAggression ();
	void apply ( Beeing& );
};

