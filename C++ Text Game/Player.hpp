/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/30/2019
Description: Player class that keeps track of courage, items carried, and current room
***************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Space.hpp"
#include <string>

// Player class declaration

class Player
{
	private:
		Space* currentRoom;
		int courage;
		bool tookDarts;
		bool tookBag;
		bool tookRock;
		bool tookLight;
		bool tookInfo;
		bool tookCode;
		bool tookKey;
		bool openedChain;
		bool brokeVisitor;
		bool openedVisitor;
		bool openedSecurity;
		bool removedGuard;
		bool wonGame;
		int items[5];

	public:
		Player();
		~Player(){}
		
		void setCurrentRoom(Space* s);
		int getCurrentRoom();

		void setBool(int itemType);
		bool checkBool(int itemType);
		void setAction(int action);
		bool checkAction(int action);
		void setCourage(int c);
		int getCourage();
		void updateCourage(int num);
		
		void addItem(int i);
		void removeItem(int i);
		bool checkItem(int i);
		void displayItems();


};

#endif

