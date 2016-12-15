#include "Profile.h"


Profile::Profile(std::string s) : p_name_(s)
{}

Profile::~Profile ()
{}

std::string Profile::getName () const
{
	return p_name_;
}

void Profile::addTrait(int t)
{
	switch (t)
	{
	case 1: traits_.push_back ( std::make_shared<Flag> () ); break;
	case 2: traits_.push_back ( std::make_shared<Superior> () ); break;
	case 3: traits_.push_back ( std::make_shared<HardSkin> () ); break;
	case 4: traits_.push_back ( std::make_shared<Armor> () ); break;
	case 5: traits_.push_back ( std::make_shared<Knife> () ); break;
	case 6: traits_.push_back ( std::make_shared<Sword> () ); break;
	case 7: traits_.push_back ( std::make_shared<Aggression> () ); break;
	case 8: traits_.push_back ( std::make_shared<Ecologic> () ); break;
	case 9: traits_.push_back ( std::make_shared<HeatSeeker> () );  break;
	case 10: traits_.push_back ( std::make_shared<BuildSeeker> () ); break;
	case 11: traits_.push_back ( std::make_shared<Walker> () ); break;
	case 12: traits_.push_back ( std::make_shared<Medicine> () );  break;
	case 13: traits_.push_back ( std::make_shared<SecondChance> () );  break;
	case 14: traits_.push_back ( std::make_shared<Student> () ); break;
	}
}

void Profile::addTrait(std::string s)
{
	if ( trait_dict_[ s ] )
	{
		addTrait ( trait_dict_[ s ] );
		trait_counter_[ s ]++;
	}
}

void Profile::remTrait(int)
{
}

std::vector<TraitPtr> Profile::getTraits() const
{
	return traits_;
}

int Profile::getTraitCount(std::string s)
{
	return trait_counter_[ s ];
}
