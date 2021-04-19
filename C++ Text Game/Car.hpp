/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description: Derived class for other rooms
***************************/

#ifndef CAR_HPP
#define CAR_HPP

#include "Space.hpp"
// Car class declaration

class Car: public Space
{
	private: 
	public:
		Car();
		Car(int num);
		~Car();
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

