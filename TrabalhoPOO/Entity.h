#pragma once
class Entity
{
public:
	virtual int getID () = 0;
	virtual const std::string & getInfo () = 0;


protected:
	int ID_;
	char rep_; // representation character. Ex.: Castle -> C

};

