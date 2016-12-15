#pragma once
#include <vector>
#include <map>

#include "Trait.h"
#include "Aggression.h"
#include "Armor.h"
#include "BuildSeeker.h"
#include "Ecologic.h"
#include "Flag.h"
#include "HardSkin.h"
#include "HeatSeeker.h"
#include "Knife.h"
#include "Medicine.h"
#include "SecondChance.h"
#include "Student.h"
#include "Superior.h"
#include "Sword.h"
#include "Walker.h"

static std::map<std::string, int> trait_dict_ = {
	{ "bandeira", 1 },
	{ "superior", 2 },
	{ "peledura", 3 },
	{ "armadura", 4 },
	{ "faca", 5 },
	{ "espada", 6 },
	{ "agressao", 7 },
	{ "ecologico", 8 },
	{ "heatseeker", 9 },
	{ "buildseeker", 10 },
	{ "walker", 11 },
	{ "remedio", 12 },
	{ "secondchance", 13 },
	{ "student", 14 },
};

class Profile
{
public:
	Profile (std::string);
	virtual ~Profile ();

	std::string getName() const;

	void addTrait ( int );
	void addTrait ( std::string );
	void remTrait ( int );
	std::vector<TraitPtr> getTraits () const;
	int getTraitCount ( std::string );

private:
	std::string p_name_;
	std::vector<TraitPtr> traits_;

	std::map<std::string, int> trait_counter_ = {
		{ "bandeira", 0 },
		{ "superior", 0 },
		{ "peledura", 0 },
		{ "armadura", 0 },
		{ "faca", 0 },
		{ "espada", 0 },
		{ "agressao", 0 },
		{ "ecologico", 0 },
		{ "heatseeker", 0 },
		{ "buildseeker", 0 },
		{ "walker", 0 },
		{ "remedio", 0 },
		{ "secondchance", 0 },
		{ "student", 0 },
	};
	
};

