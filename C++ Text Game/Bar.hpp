/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description: Derived class for other rooms
***************************/

#ifndef BAR_HPP
#define BAR_HPP

#include "Space.hpp"
#include "Player.hpp"
// Bar class declaration

class Bar: public Space
{
	private:

	public:
		Bar();
		Bar(int num);
		~Bar();
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

