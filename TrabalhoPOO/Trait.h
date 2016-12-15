#pragma once
#include <memory>

class Beeing;

class Trait
{
public:
	//TODO
	virtual void apply (Beeing&) = 0;
};

typedef std::shared_ptr<Trait> TraitPtr;
