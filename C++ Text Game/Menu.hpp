/***************************
Author: Stephanie Benamati (Catlett)
Date: 10/8/2019
Description: Menu functions for choice based programs. Will validate choices and display messages
***************************/
#include <string>

// Menu.hpp is the Menu class specification file

#ifndef MENU_HPP
#define MENU_HPP


// Menu class declaration

class Menu

{
	private:

	public:	
		void message(std::string text);
		void stringResult(std::string category, std::string result);
		void intResult(std::string category2, int result);
		void doubleResult(std::string category3, double result);
		int getNum(std::string instructions, int min, int max);
		std::string getString(std::string instructions);


};

#endif

