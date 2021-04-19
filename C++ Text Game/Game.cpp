/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description:
***************************/
#include "Menu.hpp"
#include <iostream>
#include <cstddef>//for NULL
#include "Bar.hpp"
#include "Car.hpp"
#include "Game.hpp"
#include "Courtyard.hpp"
#include "Museum.hpp"
#include "Player.hpp"

/***************
 * Game
 * default constructor
 * *************/
Game::Game()
{	
}
/***************
 * Game
 * default destructor
 * **************/
Game::~Game(){}
/**************
 * deleteRooms
 * deletes all spaces called with new
 * ************/
void Game::deleteRooms()
{
	delete player;
	player=NULL;
	delete bar;
	bar=NULL;
	delete car;
	car=NULL;
	delete courtyard;
	courtyard=NULL;
	delete museum1;
	museum1=NULL;
	delete museum2;
	museum2=NULL;
	delete museum3;
	museum3=NULL;
	delete museum4;
	museum4=NULL;
	delete museum5;
	museum5=NULL;
	
}
/*****************
 * linkRooms
 * links all rooms together when game starts
 * ***************/
void Game::linkRooms()
{
	player = new Player();
	bar = new Bar(1);
	car = new Car(2);
	courtyard = new Courtyard(3);
	museum1 = new Museum(4);
	museum2 = new Museum(5);
	museum3 = new Museum(6);
	museum4 = new Museum(7);
	museum5 = new Museum(8);

	bar->setLeft(car);
	player->setCurrentRoom(bar);//current location starts at bar

	car->setRight(bar);
	car->setBottom(courtyard);

	courtyard->setTop(car);
	courtyard->setRight(museum1);
	courtyard->setBottom(museum2);

	museum1->setLeft(courtyard);
	museum1->setBottom(museum2);
	museum1->setRight(museum4);

	museum2->setLeft(courtyard);
	museum2->setTop(museum1);
	museum2->setRight(museum3);

	museum3->setLeft(museum2);
	museum3->setTop(museum4);

	museum4->setLeft(museum1);
	museum4->setBottom(museum3);
	museum4->setRight(museum5);
	
	museum5->setLeft(museum4);

}

/*****************
 * play
 * runs game
 * ***************/
void Game::play()
{
	Menu menu;
	
	//main game loop
	do
	{	
		player->updateCourage(-1);
		printMap();

		switch (player->getCurrentRoom())
		{
			case 1: bar->describeRoom();
				player = bar->explore(player);
				break;
			case 2: car->describeRoom();
				player = car->explore(player);
				break;
			case 3: courtyard->describeRoom();
				player = courtyard->explore(player);
				break;
			case 4: museum1->describeRoom();
				player = museum1->explore(player);
				break;
			case 5: museum2->describeRoom();
				player = museum2->explore(player);
				break;
			case 6: museum3->describeRoom();
				player = museum3->explore(player);
				break;
			case 7: museum4->describeRoom();
				player = museum4->explore(player);
				break;
			case 8: museum5->describeRoom();
				player = museum5->explore(player);
				break;
		}
	}while((player->getCourage())>0 && !player->checkAction(6));
	if ((player->getCourage())<=0)
	{
		courageGone();
	}
	if (player->checkAction(6))
	{
		gameWon();
	}
}

/*****************
 * introduction
 * unique description from start of game
 * **************/
void Game::introduction()
{
	Menu menu;
	std::cout << "\nSighing to yourself, you push your stool away from the bar.\n"
		<< "	'Thanks for the drink, Jim. See you around.'\n"
		<< "	'Sure thing pal, ya take care o' yerself now.'\n"
		<< "	'I will,' you mumble, but Jim has already moved on to the next customer.\n\n\n";

	int cont=menu.getNum("Press 1 to Continue",1,1);
}
/******************
 * startPic
 * displays picture below
 * ***************/
void Game::startPic()
{
	std::cout << "\n\nWelcome to 'THE HEIST', a short, text based game where you play a previously\n"
	<< "'retired' thief down on his luck. Will you be able to pull off one last heist\n"
	<< "and take a valuable sculpture from the local museum? Or will you find that you have\n"
	<< "lost your touch... or your nerve?\n\n";

	std::cout 	<<	"\n\n   This will be my last heist...\n"
			<<	"      I swear it...                      \n\n"
			<<	"                           _____ \n"
			<<	"       __            _____/     \\_____          \n"		  
			<<	"       ||           /   _|_     _|_   \\    \n"		 	
			<<	"      /  \\         |   ////     \\\\\\\\   |  \n"					
			<<	"      |XX|  _____  \\   \\__\\ ___ /__/   / \n"	       				
			<<	" _____|  |__|~~~|___\\  /  /_____\\  \\  /_______ \n"		
			<<	"      |__|  |___|    \\___/       \\___/         \n"
			<<	" \n"
			<<	"    1-Begin the Heist    2-Give Up the Heist\n\n";	
}


/********************
 * neverstarted
 * displays below picture if player quits 
 * ******************/
void Game::neverStarted()
{
	std::cout 	<<	"\n\n                                     \n"
			<<	"          GGGG     A     M   M  EEEEE       \n"
			<<	"         G        A A    MM MM  EEE            \n"		  
			<<	"         G   GG  AAAAA   M M M  E         \n"		 	 
			<<	"          GGGG  A     A  M   M  EEEEE      \n"			 		
			<<	"                                        \n"	       		 		
			<<	"          OOOO  V     V  EEEEE  RRRR       \n"		
			<<	"         O    O  V   V   EEE    R   R   \n"
			<<	"         O    O   V V    E      RRRR     \n"
			<<	"          OOOO     V     EEEEE  R   R   \n\n\n";	

}

/****************
 * courageGone
 * displays below picture if game lost by timer running out
 * ************/
void Game::courageGone()
{
	std::cout 	<<	"\n\n                                  \n"
			<<	"         __                 \n"
			<<	"        /  \\_     You've lost your courage.        \n"
			<<	"        \\_/   \\     Your hope's gone with it too...  \n"		  
			<<	"        _/ /   \\                \n"		 	 
			<<	"       |/ /\\|   |               \n"			 		
			<<	"       /_/\\     |   You curl up on the ground,   \n"	       		 	
			<<	"       | ||\\___/    and just decide to give up.  \n"		
			<<	"       | ||                    \n"
			<<	"      /_/_/                     \n"
			<<	"                                \n\n\n";		
}
/****************
 * gameWon
 * displays below picture if game is won
 * ************/
void Game::gameWon()
{
	std::cout 	<<	"\n\n                                  \n"
			<<	"               ______               \n"
			<<	"              /      \\    \n"
			<<	"             | /\\  /\\ |      \n"		  
			<<	"             | \\/  \\/ |		\n"		 	 
			<<	"             \\        /      \n"			 		
			<<	"              \\______/        \n"	       		 	
			<<	"             ___|  |___                \n"		
			<<	"            | [][][][] |     \n"
			<<	"            \\ ()()()() /    \n"
			<<	"             \\________/           \n\n"
			<<	"          CONGRATULATIONS! \n"
			<<	"    You've pulled off the heist!\n\n\n";		
}

/****************
 * printMap
 * shows where the player is on the map
 * ************/
void Game::printMap()
{ 
	switch(player->getCurrentRoom())
	{
		case 1:	std::cout  
			<< "      MAP: Your Location is Marked with 'X'		\n"
			<< "  _______                 ___________________       \n"
			<< " |Car    |               |Bar                |      \n"
			<< " |       |---------------|         X         |      \n"
			<< " |_______|               |___________________|      \n"
			<< "     |                                              \n"
			<< "     |                                              \n"
			<< "     |                 Museum                       \n"
			<< "  ___|___     _______     _______     _______	\n"
			<< " | Court |   |       |   |       |   |       |	\n"
			<< " | -yard |---|       |---|       |---|       |	\n"
			<< " |       |   |_______|   |_______|   |_______|	\n"
			<< " |       |       |           |			\n"
			<< " |_______|    ___|___     ___|___        	        \n"
			<< "     |       |       |   |       |       N      	\n"
			<< "     --------|       |---|       |     W-|-E     	\n"
			<< "             |_______|   |_______|       S    	\n"
			<< "							\n";
			break;
		case 2:	std::cout  
			<< "      MAP: Your Location is Marked with 'X'		\n"
			<< "  _______                 ___________________       \n"
			<< " |Car    |               |Bar                |      \n"
			<< " |   X   |---------------|                   |      \n"
			<< " |_______|               |___________________|      \n"
			<< "     |                                              \n"
			<< "     |                                              \n"
			<< "     |                 Museum                       \n"
			<< "  ___|___     _______     _______     _______	\n"
			<< " | Court |   |       |   |       |   |       |	\n"
			<< " | -yard |---|       |---|       |---|       |	\n"
			<< " |       |   |_______|   |_______|   |_______|	\n"
			<< " |       |       |           |			\n"
			<< " |_______|    ___|___     ___|___        	        \n"
			<< "     |       |       |   |       |       N      	\n"
			<< "     --------|       |---|       |     W-|-E     	\n"
			<< "             |_______|   |_______|       S    	\n"
			<< "							\n";
			break;
		case 3:	std::cout  
			<< "      MAP: Your Location is Marked with 'X'		\n"
			<< "  _______                 ___________________       \n"
			<< " |Car    |               |Bar                |      \n"
			<< " |       |---------------|                   |      \n"
			<< " |_______|               |___________________|      \n"
			<< "     |                                              \n"
			<< "     |                                              \n"
			<< "     |                 Museum                       \n"
			<< "  ___|___     _______     _______     _______	\n"
			<< " | Court |   |       |   |       |   |       |	\n"
			<< " | -yard |---|       |---|       |---|       |	\n"
			<< " |       |   |_______|   |_______|   |_______|	\n"
			<< " |   X   |       |           |			\n"
			<< " |_______|    ___|___     ___|___        	        \n"
			<< "     |       |       |   |       |       N      	\n"
			<< "     --------|       |---|       |     W-|-E     	\n"
			<< "             |_______|   |_______|       S    	\n"
			<< "							\n";
			break;
		case 4:	std::cout  
			<< "      MAP: Your Location is Marked with 'X'		\n"
			<< "  _______                 ___________________       \n"
			<< " |Car    |               |Bar                |      \n"
			<< " |       |---------------|                   |      \n"
			<< " |_______|               |___________________|      \n"
			<< "     |                                              \n"
			<< "     |                                              \n"
			<< "     |                 Museum                       \n"
			<< "  ___|___     _______     _______     _______	\n"
			<< " | Court |   |       |   |       |   |       |	\n"
			<< " | -yard |---|   X   |---|       |---|       |	\n"
			<< " |       |   |_______|   |_______|   |_______|	\n"
			<< " |       |       |           |			\n"
			<< " |_______|    ___|___     ___|___        	        \n"
			<< "     |       |       |   |       |       N      	\n"
			<< "     --------|       |---|       |     W-|-E     	\n"
			<< "             |_______|   |_______|       S    	\n"
			<< "							\n";
			break;
		case 5:	std::cout  
			<< "      MAP: Your Location is Marked with 'X'		\n"
			<< "  _______                 ___________________       \n"
			<< " |Car    |               |Bar                |      \n"
			<< " |       |---------------|                   |      \n"
			<< " |_______|               |___________________|      \n"
			<< "     |                                              \n"
			<< "     |                                              \n"
			<< "     |                 Museum                       \n"
			<< "  ___|___     _______     _______     _______	\n"
			<< " | Court |   |       |   |       |   |       |	\n"
			<< " | -yard |---|       |---|       |---|       |	\n"
			<< " |       |   |_______|   |_______|   |_______|	\n"
			<< " |       |       |           |			\n"
			<< " |_______|    ___|___     ___|___        	        \n"
			<< "     |       |       |   |       |       N      	\n"
			<< "     --------|   X   |---|       |     W-|-E     	\n"
			<< "             |_______|   |_______|       S    	\n"
			<< "							\n";
			break;
		case 6:	std::cout  
			<< "      MAP: Your Location is Marked with 'X'		\n"
			<< "  _______                 ___________________       \n"
			<< " |Car    |               |Bar                |      \n"
			<< " |       |---------------|                   |      \n"
			<< " |_______|               |___________________|      \n"
			<< "     |                                              \n"
			<< "     |                                              \n"
			<< "     |                 Museum                       \n"
			<< "  ___|___     _______     _______     _______	\n"
			<< " | Court |   |       |   |       |   |       |	\n"
			<< " | -yard |---|       |---|       |---|       |	\n"
			<< " |       |   |_______|   |_______|   |_______|	\n"
			<< " |       |       |           |			\n"
			<< " |_______|    ___|___     ___|___        	        \n"
			<< "     |       |       |   |       |       N      	\n"
			<< "     --------|       |---|   X   |     W-|-E     	\n"
			<< "             |_______|   |_______|       S    	\n"
			<< "							\n";
			break;
		case 7:	std::cout  
			<< "      MAP: Your Location is Marked with 'X'		\n"
			<< "  _______                 ___________________       \n"
			<< " |Car    |               |Bar                |      \n"
			<< " |       |---------------|                   |      \n"
			<< " |_______|               |___________________|      \n"
			<< "     |                                              \n"
			<< "     |                                              \n"
			<< "     |                 Museum                       \n"
			<< "  ___|___     _______     _______     _______	\n"
			<< " | Court |   |       |   |       |   |       |	\n"
			<< " | -yard |---|       |---|   X   |---|       |	\n"
			<< " |       |   |_______|   |_______|   |_______|	\n"
			<< " |       |       |           |			\n"
			<< " |_______|    ___|___     ___|___        	        \n"
			<< "     |       |       |   |       |       N      	\n"
			<< "     --------|       |---|       |     W-|-E     	\n"
			<< "             |_______|   |_______|       S    	\n"
			<< "							\n";
			break;
		case 8:	std::cout  
			<< "      MAP: Your Location is Marked with 'X'		\n"
			<< "  _______                 ___________________       \n"
			<< " |Car    |               |Bar                |      \n"
			<< " |       |---------------|                   |      \n"
			<< " |_______|               |___________________|      \n"
			<< "     |                                              \n"
			<< "     |                                              \n"
			<< "     |                 Museum                       \n"
			<< "  ___|___     _______     _______     _______	\n"
			<< " | Court |   |       |   |       |   |       |	\n"
			<< " | -yard |---|       |---|       |---|   X   |	\n"
			<< " |       |   |_______|   |_______|   |_______|	\n"
			<< " |       |       |           |			\n"
			<< " |_______|    ___|___     ___|___        	        \n"
			<< "     |       |       |   |       |       N      	\n"
			<< "     --------|       |---|       |     W-|-E     	\n"
			<< "             |_______|   |_______|       S    	\n"
			<< "							\n";
			break;
		
	}	
}

