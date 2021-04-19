/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description: Derived class for other rooms
***************************/

#ifndef MUSEUM_HPP
#define MUSEUM_HPP

#include "Space.hpp"
// Courtyard class declaration

class Museum: public Space
{
	private:
		bool gotStatue;
	public:
		Museum();
		Museum(int num);
		~Museum();
		virtual void setTop(Space* t);
		virtual void setBottom(Space* b);
		virtual void setLeft(Space* l);
		virtual void setRight(Space* r);
		
		virtual void describeRoom();
		virtual Player* explore(Player* user);
		virtual void interact(Player* p);
		virtual int getCurrentRoom();
};

#endif

