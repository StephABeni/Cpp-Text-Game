/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description:
***************************/
#include "Bar.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include <iostream>
/************
 * default constructor
 * *********/
Bar::Bar(){}

/*********
 * constructor
 * ******/
Bar::Bar(int num)
{
	roomNum=num;
}
/*********
 * default destructor
 * ******/
Bar::~Bar(){}

/***********
 *setTop
 *links room to another on top of it
 * *********/
void Bar::setTop(Space* t)
{
	top=t;
}

/***********
 *setBottom
 *links room to another below it
 * *********/
void Bar::setBottom(Space* b)
{
	bottom=b;
}

/***********
 *setLeft
 *links room to another to the left of it
 * *********/
void Bar::setLeft(Space* l)
{
	left=l;
}

/***********
 *setRight
 *links room to another to the right of it
 * *********/
void Bar::setRight(Space* r)
{
	right=r;
}

/***********
 * describe room
 * prints initial description of room
 * *********/
void Bar::describeRoom()
{
	
	std::cout << "\nYour gaze pans over the most popular bar around--though that's not saying much.\n"	
		<< "The place is packed. In a small, hell-hole of a town like this, it always is.\n"
		<< "The closet alcoholics, the drink-to-forgets, the crooks and sinners...\n";
}

/************
 * explore
 * gives descriptions of when the player explores the room. returns new space when they leave to another room
 * *********/
Player* Bar::explore(Player* user)
{
	Menu menu;
	Game game;
	int direction=0;
	int leave=0;

	std::cout << "\nTo the north is a sticky bar-top, and the bar-keep, Jim.\n"
		<< "To the south is a wall of booths stuffed with various groups of patrons.\n"
		<< "To the west is a glass door with a stained 'OPEN' sign hanging in the center.\n"	
		<< "To the east is a group of drunken frats playing darts (poorly).\n";
	
	
	do
	{
		direction = menu.getNum("\nWhat would you like to do?\n   1-Move North (Towards Bar)\n   2-Move South (Towards Booths)\n   3-Move West (Towards Exit)\n   4-Move East (Towards Dart Board)\n   5-GIVE UP",1,5);

		switch(direction)
		{
			case 1: //forward
				menu.message("\nYou go towards the bar to try and get Jim's attention.\n");
				menu.message("... \n");
				menu.message("He seems busy trying to break up an argument. You'd better not inturrupt.\n");
				if(top!=NULL)
				{
					user->setCurrentRoom(top);
				}
				break;
			case 2: //backward
				menu.message("\nYou move towards the line of booths, but whenever you approach a table\nthe patrons give you a strange look or tell you to get lost.\n");
				if(bottom!=NULL)
				{
					user->setCurrentRoom(bottom);
				}
				break;
			case 3: //left
				menu.message("\nYou decide you've had enough of the smell of sweat, depression, and regret.\nYou head towards the door.");
				leave=menu.getNum("The door is clouded gray and grimy with the cigarette smoke that has settled on the glass. \nLeave Bar?\n   1-Yes\n   2-No",1,2);
				if(left!=NULL && leave==1)
				{
					user->setCurrentRoom(left);
				}
				break;
			case 4: //right
				menu.message("\nYou wander over towards the group of young men.\nThey've started to roughhouse with each other instead of throwing darts.\n");
				interact(user);
				if(right!=NULL)
				{
					user->setCurrentRoom(right);
				}
				break;
			case 5: //Give up
				//changeCourage(40);
				user->setCourage(0);
				break;
		}
	}while(leave!=1 && direction!=5);
	return user;
}

/************
 * interact
 * when player finds space with object, lets them interact with the space
 * *********/
void Bar::interact(Player* p)
{
	Menu menu;
	int darts=0;
	
	do
	{
		if(p->checkBool(1))
		{
			darts=menu.getNum("\nThey're still roughhousing.\n   1-Leave\n   2-Throw a Dart at the Board\n ",1,2);
			switch(darts)
			{
				case 1:
					menu.message("\nYou've seen enough. It's time to go.\n");
					break;
				case 2:
					menu.message("\nBULLSEYE!\nThe boys pause to look towards you for a minute...\nThey unanimously give you a nod of respect, then continue wrestling.\n");
					break;
			}
	
		}
		else
		{
			darts=menu.getNum("\nYou notice that during their tussle, they've dropped some darts on the ground.\n   1-Leave\n   2-Throw a Dart at the Board\n   3-Pocket the Darts",1,3);
			switch(darts)
			{
				case 1:
					menu.message("\nYou've seen enough. It's time to go.\n");
					break;
				case 2:
					menu.message("\nBULLSEYE!\nThe boys pause to look towards you for a minute...\nThey unanimously give you a nod of respect, then continue wrestling.\n");
					break;
				case 3:
					menu.message("\nYou sneak the darts into your pocket and no one seems to notice.\nOnce a thief, always a thief, you suppose.\n");
					p->setBool(1);
					p->addItem(1);
					p->displayItems();
					break;
			}
		}
	}while(darts!=1);
}

/************
 * getCurrentroom
 * returns the room number of the current room
 * **********/
int Bar::getCurrentRoom()
{
	return roomNum;
}
