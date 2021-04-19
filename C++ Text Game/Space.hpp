/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description: Base class for other rooms
***************************/

#ifndef SPACE_HPP
#define SPACE_HPP

class Player;
// Space class declaration

class Space
{
	protected:
		Space* top; //pointer to linked space above
		Space* bottom; //pointer to linked space below
		Space* left; //pointer to linked space left
		Space* right; //pointer to linked space right
		int roomNum;
	public:
		Space();
		~Space();
		virtual void setTop(Space* t)=0;
		virtual void setBottom(Space* b)=0;
		virtual void setLeft(Space* l)=0;
		virtual void setRight(Space* r)=0;
		
		virtual void describeRoom()=0;
		virtual Player* explore(Player* p)=0;
		virtual void interact(Player* p)=0;
		virtual int getCurrentRoom()=0;




};

#endif

