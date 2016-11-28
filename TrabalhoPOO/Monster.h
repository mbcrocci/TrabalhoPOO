#pragma once
class Monster
{
public:
	Monster ();
	~Monster ();

private:
	int health_ = 10;
	int power_ = 10;
	int speed_;
	int attack_;
	int defense_;
};

