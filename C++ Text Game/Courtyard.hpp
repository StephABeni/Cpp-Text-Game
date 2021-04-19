/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description: Derived class for other rooms
***************************/

#ifndef COURTYARD_HPP
#define COURTYARD_HPP

#include "Space.hpp"
// Courtyard class declaration

class Courtyard: public Space
{
	private:
	public:
		Courtyard();
		Courtyard(int num);
		~Courtyard();
		virtual void setTop(Space* t);
		virtual void setBottom(Space* b);
		virtual void setLeft(Space* l);
		virtual void setRight(Space* r);
		
		virtual void describeRoom();
		virtual Player* explore(Player* user);
		virtual void interact(Player* p);
		void interact2(Player* p);
		virtual int getCurrentRoom();
};

#endif

