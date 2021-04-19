/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description:
***************************/
#include "Car.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include <iostream>
/************
 * default constructor
 * *********/
Car::Car(){}

/*********
 * constructor
 * ******/
Car::Car(int num)
{
	roomNum=num;
}
/*********
 * default destructor
 * ******/
Car::~Car(){}

/***********
 *setTop
 *links room to another on top of it
 * *********/
void Car::setTop(Space* t)
{
	top=t;
}

/***********
 *setBottom
 *links room to another below it
 * *********/
void Car::setBottom(Space* b)
{
	bottom=b;
}

/***********
 *setLeft
 *links room to another to the left of it
 * *********/
void Car::setLeft(Space* l)
{
	left=l;
}

/***********
 *setRight
 *links room to another to the right of it
 * *********/
void Car::setRight(Space* r)
{
	right=r;
}

/***********
 * describe room
 * prints initial description of room
 * *********/
void Car::describeRoom()
{
	Menu menu;
	std::cout << "\nYour mind wanders as you walk. Are you really going to try and pull off another heist?\n"
		<< "It's been years since you've left theiving behind... but, what else could pay your debt?\n"
	       	<< "You sigh deeply--you should've just become an accountant when you had the chance.\n"	
		<< "\nThe walk is long, but before you know it the car is in sight.\n";
	

}

/************
 * explore
 * gives descriptions of when the player explores the room. returns new space when they leave to another room
 * *********/
Player* Car::explore(Player* user)
{
	Menu menu;
	Game game;
	int direction=0;
	int leave=0;
	if (user->checkBool(2))
	{
		menu.message("	'Now,' you think to yourself, 'where did I stash that bag again?'");
	}
	std::cout << "\nTo the north is a bulletin board covered in posters.\n"
		<< "To the south is the road that will take you to the target of your heist--The Museum.\n"
		<< "To the west is your unassuming gray sedan. You've already unlocked all the doors.\n"	
		<< "To the east is the path back to the bar.\n";
	
	do
	{
		direction = menu.getNum("\nWhat would you like to do?\n   1-Move North (Check Bulletin)\n   2-Move South (Drive to Museum)\n   3-Move West (Check Car)\n   4-Move East (Return to Bar)\n   5-GIVE UP",1,5); 
	
		switch(direction)
		{
			case 1://forwards
				menu.message("\nYou walk up to the bulletin board and try to make sense of the mess of papers.\nThe only one that stands out to you is the advertisment for the museum.\n\n");
				menu.message("   Masterwork Paintings!\n   Ancient artifacts!\n   Get your ticket today and\n   see what the hubbub's about.\n");
				
				//move if theres a room in that direction
				if(top!=NULL)
				{
					user->setCurrentRoom(top);
				}
				break;
			case 2://backwards
				if(user->checkBool(2))
				{
					leave=menu.getNum("You start up the car and get in. You're really doing this...\nDrive to museum?\n   1-Yes\n   2-No",1,2);
				}
				else
				{
					leave=menu.getNum("\nYou start up the car and get in. You figure you can probably look for the bag later.\nDrive to museum?\n   1-Yes\n   2-No",1,2);
				}
				//move if theres a room in that direction
				if(bottom!=NULL && leave==1)
				{
					menu.message("You park a few blocks away from the museum and start walking.");
					user->setCurrentRoom(bottom);
				}
				break;
			case 3://left
				menu.message("\nThe car is, admittedly, nothing fancy. Rule #1 of successful theiving is that fancy gets you seen, and seen gets you caught.\nWait... that's not quite a rule, is it?\n");
				interact(user);

				//move if theres a room in that direction
				if(left!=NULL)
				{
					user->setCurrentRoom(left);
				}
				break;		
			case 4://right
				leave=menu.getNum("\nYou look back in the direction of the bar. Did you really get everything you needed?\nReturn to Bar?\n  1-Yes\n   2-No",1,2);			
				//move if theres a room in that direction
				if(right!=NULL && leave==1)
				{	
					user->setCurrentRoom(right);
				}
				break;
			case 5://Give up
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
void Car::interact(Player* p)
{
	Menu menu;
	Game game;
	int bag=0;
	
	do
	{
		bag=menu.getNum("What would you like to do?\n   1-Stop Searching\n   2-Search Trunk\n   3-Search Beneath the Hood\n   4-Search Under the Car\n   5-Search Cab",1,5);
		switch(bag)
		{
			case 1:
				menu.message("\nYou're done looking. It's time to go.\n");
				break;
			case 2:
				menu.message("\nYou rifle through the contents of the trunk...geez, when's the last time you opened this thing?\nYou find copius amounts of dust and dirt, some old cleats, and a shake-weight,\nbut nothing that you'd consider taking with you.\n");
				break;
			case 3:
				menu.message("\nYou pop the hood and find a large black widow has made a nice home in your engine compartment.\nYou promptly close it.\n");
				break;
			case 4:
				menu.message("\nYou look around and are relieved that there's no one nearby.\nDropping to hands and knees, you scan the car undercarriage for anything out of the ordinary...\n");
				if(!p->checkBool(2))
				{
					int take=menu.getNum("\nAha!\n\nA small black bag is duct-taped to the underside of the car.\n   1-Grab it\n   2-Leave it\n",1,2);
					if (take==1)
					{
						menu.message("You carefully peel the tape away and the bag falls into your outstretched hand.\nYou unzip it and see that your old theives tools (a lockpick and a hacking module) are still intact.\n");
						//update inventory
						p->setBool(2);
						p->addItem(2);
						p->addItem(3);
						p->displayItems();
					}
					else
					{
						menu.message("You decide to leave it for later.\n");
					}
				}
				else if(p->checkBool(2))
				{
					menu.message("There's nothing of note under the car, anymore.\n");
				}
				break;
			case 5:
				menu.message("You open the backseat to a small avalanche of empty gatorade and water bottles.\nYou quickly shove the garbage back in to the car... you should really clean more.\n");
				break;
		}
	}while(bag!=1);

}
/************
 * getCurrentroom
 * returns the room number of the current room
 * **********/
int Car::getCurrentRoom()
{
	return roomNum;
}
