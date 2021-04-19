/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description:
***************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "Space.hpp"
#include "Player.hpp"
// GAME class declaration

class Game
{
	private:
		Player* player; //keeps track of player location

		Space* bar;
		Space* car;
		Space* courtyard;
		Space* museum1; //museum rooms
		Space* museum2;
		Space* museum3;
		Space* museum4;
		Space* museum5;

	public:
		Game();
		~Game();
		void deleteRooms();
		void linkRooms(); //links all rooms into map when game starts
		void play();
		
		void introduction();
		void startPic();//displays at start of game
		void neverStarted();//displays if quit at start
		void courageGone();//displays if courage=0
		void gameWon();

		void printMap();


};

#endif

