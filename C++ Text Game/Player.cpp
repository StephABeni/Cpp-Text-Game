/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/30/2019
Description:function definitions for player class
***************************/
#include "Player.hpp"
#include "Menu.hpp"
#include <iostream>

/***********
 * default constructor
 * sets up player
 * *********/
Player::Player()
{
	courage=31;
	tookDarts=false;
	tookBag=false;
	tookRock=false;
	tookLight=false;
	tookInfo=false;
	tookCode=false;
	tookKey=false;
	openedChain=false;
	brokeVisitor=false;
	openedVisitor=false;
	openedSecurity=false;
	removedGuard=false;
	wonGame=false;
	items[0]=0;
	items[1]=0;
	items[2]=0;
	items[3]=0;
	items[4]=0;
}
/*********
 * setCurrentRoom
 * will set space pointer to a passed pointer address
 * *******/
void Player::setCurrentRoom(Space* s)
{
	currentRoom=s;
}
/***********
 * getCurrentRoom
 * returns room player is in
 **********/
int Player::getCurrentRoom()
{
	return (currentRoom->getCurrentRoom());
}

/************
 * setBool
 * depending on int entered, will change bool value to true
 * *********/
void Player::setBool(int itemType)
{
	//1-Darts, 2-Lockpick + Hacking Module, 3-Rock, 4-Light, 5-Info, 6-Code, 7-Key
	switch(itemType)
	{
		case 1: tookDarts=true;
			break;
		case 2: tookBag=true;
			break;
		case 3: tookRock=true;
			break;
		case 4: tookLight=true;
			break;
		case 5: tookInfo=true;
			break;
		case 6: tookCode=true;
			break;
		case 7: tookKey=true;
			break;
	}

}
/************
 * checkBool
 * depending on int entered, will return bool value as true or false
 * *********/
bool Player::checkBool(int itemType)
{
	//1-Darts, 2-Lockpick + Hacking Module, 3-Rock, 4-Light, 5-Info, 6-Code, 7-Key
	switch(itemType)
	{
		case 1: if(tookDarts==true)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 2: if(tookBag==true)
			{
				return true;
			}			
			else
			{
				return false;
			}

			break;
		case 3: if(tookRock==true)
			{
				return true;
			}		
			else
			{
				return false;
			}

			break;
		case 4: if(tookLight==true)
			{
				return true;
			}			
			else
			{
				return false;
			}

			break;
		case 5: if(tookInfo==true)
			{
				return true;
			}			
			else
			{
				return false;
			}

			break;
		case 6: if(tookCode==true)
			{
				return true;
			}			
			else
			{
				return false;
			}

				break;
		case 7: if(tookKey==true)
			{
				return true;
			}			
			else
			{
				return false;
			}

			break;
	}

}
/************
 * setaction
 * depending on int entered, will change bool value to true
 * *********/
void Player::setAction(int Action)
{
	switch(Action)
	{
		case 1: openedChain=true;
			break;
		case 2: brokeVisitor=true;
			break;
		case 3: openedVisitor=true;
			break;
		case 4: openedSecurity=true;
			break;
		case 5: removedGuard=true;
			break;
		case 6: wonGame=true;
			break;
	}

}
/************
 * checkBool
 * depending on string entered, will return bool value as true or false
 * *********/
bool Player::checkAction(int action)
{
	switch(action)
	{
		case 1: if(openedChain==true)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 2: if(brokeVisitor==true)
			{
				return true;
			}			
			else
			{
				return false;
			}

			break;
		case 3: if(openedVisitor==true)
			{
				return true;
			}			
			else
			{
				return false;
			}

			break;
		case 4: if(openedSecurity==true)
			{
				return true;
			}			
			else
			{
				return false;
			}
			break;
		case 5: if(removedGuard==true)
			{
				return true;
			}			
			else
			{
				return false;
			}
			break;
		case 6:	if(wonGame==true)
			{
				return true;
			}
			else
			{
				return false;
			}
	}

}

/***********
 * setCourage
 * sets courage to passed int
 * *********/
void Player::setCourage(int c)
{
	courage=c;
}
/***********
 * getCourage
 * returns courage int
 * *********/
int Player::getCourage()
{
	return courage;
}

/*****************
 * updateCourage
 * removes 1 courage for each movement made by the player
 * *************/
void Player::updateCourage(int num)
{
	Menu menu;
	courage=courage+num;
	if (courage<0)
	{
		courage=0;
	}
	std::cout	<< "===============================================\n"
			<< "            Courage Remaining: " << courage << "\n" 
			<< "===============================================\n";
	
	if(courage==30)
	{
		menu.message("With this much alcohol in your veins,\n you feel like you can do anything!\n\n");
	}
	if(courage==15)
	{
		menu.message("You're starting to sober up... \nmaybe this wasn't such a great idea?\n\n");
	}
	if(courage==5)
	{
		menu.message("This was a terrible idea.\n\n");
	}	
}


/******************
 * addItem
 * adds an item to the array, then prints contents
 * ***************/
void Player::addItem(int i)
{
	Menu menu;
	for(int count=0; count<5; count++)
	{
		if(items[count]==0)
		{
			menu.message("Item added to Inventory!");
			items[count]=i;//add item to empty space
			count=6;//exit loop
		}
	}
	
}

/******************
 * addItem
 * adds an item to the array, then prints contents
 * ***************/
void Player::removeItem(int i)
{
	Menu menu;
	for(int count=0; count<5; count++)
	{
		if(items[count]==i)
		{
			menu.message("\n\nItem removed from Inventory!");
			items[count]=0;//add empty space to array
			count=6;//exit loop
		}
	}
	
}

/*****************
 * checkItem
 * returns true if item is in array, otherwise false
 * ***************/
bool Player::checkItem(int i)
{
	int count;
	for (count=0; count<5; count++)
	{
		if(items[count]==i)
		{
			return true;
			count=6; //exit loop
		}
	}
	if(count!=6)
	{
		return false;
	}
}

/*****************
 * displayItems
 * shows what the player has in their inventory
 * *************/
void Player::displayItems()
{
	Menu menu;
	menu.message("Current Inventory: ");
	
	for(int count=0; count<5; count++)
	{

		if(items[count]==1)
		{
			menu.message("   Darts");
		}
		if(items[count]==2)
		{
			menu.message("   Lockpick");
		}
		if(items[count]==3)
		{
			menu.message("   Hacking Module");
		}
		if(items[count]==4)
		{
			menu.message("   Rock");
		}
		if(items[count]==5)
		{
			menu.message("   Flashlight");
		}
		if(items[count]==6)
		{
			menu.message("   Combination Code - 721");
		}
		if(items[count]==7)
		{
			menu.message("   Key");
		}

	}
	menu.message("\n\n");
}



