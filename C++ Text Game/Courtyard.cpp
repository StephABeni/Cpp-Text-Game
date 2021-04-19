/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description:
***************************/
#include "Courtyard.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include <iostream>
/************
 * default constructor
 * *********/
Courtyard::Courtyard(){}

/*********
 * constructor
 * ******/
Courtyard::Courtyard(int num)
{
	roomNum=num;
}
/*********
 * default destructor
 * ******/
Courtyard::~Courtyard(){}

/***********
 *setTop
 *links room to another on top of it
 * *********/
void Courtyard::setTop(Space* t)
{
	top=t;
}

/***********
 *setBottom
 *links room to another below it
 * *********/
void Courtyard::setBottom(Space* b)
{
	bottom=b;
}

/***********
 *setLeft
 *links room to another to the left of it
 * *********/
void Courtyard::setLeft(Space* l)
{
	left=l;
}

/***********
 *setRight
 *links room to another to the right of it
 * *********/
void Courtyard::setRight(Space* r)
{
	right=r;
}

/***********
 * describe room
 * prints initial description of room
 * *********/
void Courtyard::describeRoom()
{
	
	std::cout << "\nThe partially frozen sidewalk is slick under your feet as you approach the entrance.\n"	
		<< "The weather has taken a turn for the worse, it seems, as the chill wind whips around you.\n"
		<< "You'd better get out of the elements quickly. You're not really dressed for prolonged cold.\n"
		<< "**Note: Each movement (north, south, east, west) while in the courtyard will cost\n1 point of courage, due to the disheartening weather conditions**\n";
}

/************
 * explore
 * gives descriptions of when the player explores the room. returns new space when they leave to another room
 * *********/
Player* Courtyard::explore(Player* user)
{
	Menu menu;
	int direction=0;
	int leave=0;

	std::cout << "\nTo the north is the way back to the car.\n"
		<< "To the south is a manicured dirt trail with a sign that says 'Employees Only'.\n"
		<< "To the west is the Museum parking lot.\n"	
		<< "To the east is the standard visitor entrance. The doors are shut.\n";
	
	
	do
	{
		direction = menu.getNum("\nWhat would you like to do?\n   1-Move North (Towards Car)\n   2-Move South (Towards Employee-Only Trail)\n   3-Move West (Towards Parking Lot)\n   4-Move East (Towards Visitor Entrance)\n   5-GIVE UP",1,5);

		switch(direction)
		{
			case 1: //forward
				user->updateCourage(-1);
				leave=menu.getNum("\nYou worry that maybe you missed something. You figure a quick check can't hurt anything, right?\nWalk back to car?\n   1-Yes\n   2-No",1,2);
				if(top!=NULL && leave==1)
				{
					menu.message("You return to the car trying to remember if you've forgotten anything.\n");
					user->setCurrentRoom(top);
				}
				break;
			case 2: //backward
				user->updateCourage(-1);
				menu.message("\n'Employees Only?' you whisper incredulously.\n'Now that's practically an invitation! They should know better.'");
				menu.message("You step off the pavement and onto the frozen earthen path, seeing where it leads.\n");
				interact(user);
				if(user->checkAction(1))
				{
					leave=menu.getNum("The employee entrace is open!\nA hot breeze wafts out from inside the building and warms your face.\nGo inside the museum?\n   1-Yes\n   2-No",1,2);
					if(bottom!=NULL && leave==1)
					{
						user->setCurrentRoom(bottom);
					}
				}	
				break;
			case 3: //left 
				user->updateCourage(-1);
				menu.message("You decide to check the parking lot before you try and get into the building.\n");
				interact2(user);
				if(left!=NULL)
				{
					user->setCurrentRoom(left);
				}
				break;
			case 4: //right
				user->updateCourage(-1);
				if(user->checkAction(2) || user->checkAction(3)) //if player broke doors or opened doors
				{
					leave=menu.getNum("You've already opened the visitors entrance.\nGo inside the musuem?\n   1-Yes\n   2-No",1,2);
				}
				else
				{
					menu.message("You figure the regular visitor entrance is as good a place to start as any.\nThere is a sign in front of the door that lists the operating hours of the Museum.\nUnsuprisingly it's closed now.\nThe double glass doors appear to be locked from the inside, without a clear way to open them.\nYou could probably break the glass with something to get in, though?\n");
					if(user->checkItem(4))//if player picked up rock
					{
						int throwRock=menu.getNum("Break the window with that nifty rock you found?\n   1-Yes\n   2-No",1,2);
						if(throwRock==1)
						{
							menu.message("You feel an uncontrollable urge to throw caution to the wind.\nYou grasp the rock from one of your pockets and chuck it with all of your might at the doors...\n\nThe glass is no match for you! However... the security notified by the alarm system might be.\nA loud beeping rings out from inside the depths of the museum, and an automated message plays over the loudspeakers.\n	'BE ADVISED. SECURITY INCOMING IN 15 MINUTES. WARNING. BE ADVISED...'\n\n***Courage set to 15***");
							user->setCourage(16);
							user->updateCourage(-1);
							user->setAction(2);
							user->removeItem(4);
							user->displayItems();
							leave=menu.getNum("Well, what's done is done, you suppose.\nGo Inside the Museum?\n   1-Yes\n   2-No",1,2);
						}
						else
						{
							menu.message("Good call! Probably for the best.");
						}
					}
					else
					{
						menu.message("You don't feel keen on breaking the glass with your bare hands and leaving your DNA everywhere.\nYou decide to leave it alone for now.");
					}
				}
				if(right!=NULL && leave==1)
				{
					user->setCurrentRoom(right);
				}
				break;
			case 5://quit
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
void Courtyard::interact(Player* p)
{
	Menu menu;
	int choice=0;
	
	if(!p->checkAction(1))
	{
		menu.message("The path takes you to a steel door, chained shut with a padlock.");
		menu.message("	'That just seems excessive!' you comment.\nHave you always had this habit of talking to yourself?\n	'...Nah.'");
		do
		{
			choice=menu.getNum("Try to open it?\n   1-Take the path back\n   2-Open it\n   3-No?",1,3);
			if(choice==2 && p->checkItem(2)) //2 is code for lockpick
			{
				menu.message("You look through your pockets and fish out the lockpick.\nAfter much fiddling and cursing, the padlock falls to the floor...\nalong with the broken shards of your lockpick. You grimace.");
				menu.message("	'Hopefully this isn't a sign of what's to come.'");
				p->removeItem(2);
				p->displayItems();
				p->setAction(1);
			}
			else if(choice==2 && !p->checkItem(2))
			{
				menu.message("You rummage through your pockets, but don't find anything that can help you open the door");
			}
			else if (choice==3)
			{
				menu.message("You decide to leave the locked door alone for now.");
			}	
		}while(choice!=1 && !p->checkAction(1));
	}
	
}
/************
 * interact2
 * when player finds space with object, lets them interact with the space
 * *********/
void Courtyard::interact2(Player* p)
{
	Menu menu;
	int rock=0;
	do
	{
		menu.message("The large parking lot is empty, save for a few patches of litter.");
		if(p->checkItem(4))
		{
			menu.message("You already got a nice rock! What else could you possibly want from an empty parking l--\nwait. Don't answer that.");
			rock=2;
		}
		else
		{
			rock=menu.getNum("You do notice, however, that there is a nice, fist-sized rock by a lamppost.\nPick it up?\n   1-Yes\n   2-No",1,2);
			if (rock==1)
			{
				menu.message("Nice!");
				p->setBool(3);
				p->addItem(4);
				p->displayItems();
			}
			else
			{
				menu.message("You decide to leave the rock alone. No sense having it weigh you down at the moment.");
			}
		}
	}while(rock!=2);
}

/************
 * getCurrentroom
 * returns the room number of the current room
 * **********/
int Courtyard::getCurrentRoom()
{
	return roomNum;
}
