#pragma once
#include "Trait.h"
class Aggression :
	public Trait
{
public:
	Aggression ();
	~Aggression ();

	void apply ( Beeing& );
};

