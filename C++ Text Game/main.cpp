/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description:
***************************/
#include <iostream>
#include "Menu.hpp"
#include "Game.hpp"

int main()
{
	Menu menu;
	Game game;

	game.linkRooms();
	game.startPic();

	int play=menu.getNum("",1,2);
	
	if(play==1)
	{
		game.introduction();
		game.play();
	}
	else
	{
		menu.message("\nYou shake your head angrily, trying to clear the cobwebs.\nNO! You decided to leave that life behind, didn't you?\nYou'll find another way... somehow...\n");
		game.neverStarted();
	}
	game.deleteRooms();
	return 0;
}
