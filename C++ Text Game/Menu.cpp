/***************************
Author: Stephanie Benamati (Catlett)
Date: 9/25/2019
Description: Menu functions for choice based programs. Will validate choices and display messages
***************************/
#include "Menu.hpp"
#include "getNum.hpp"
#include <string>
#include <iostream>

/**************
 * message
 * displays a message to the user
 * *************/

void Menu::message(std::string text)
{
	std::cout << text << std::endl;
}


/**************
 * getNum
 * asks a user for an integer, and loops until valid input is entered
 * ***********/
//got help from TA Andrew Derringer for this function on 10/8/2019. Adapted from an example he gave

int Menu::getNum(std::string instructions, int min, int max)
{
	int num;
	std::cout << instructions << std::endl; //prints user instructions
	
	num=getInt();
	while (num<min || num>max)
	{
		std::cout << "Invalid data, enter an integer between " << min <<  " and " << max << std::endl;
		num=getInt();
	}
	return num;
}

/****************
 * stringResult
 * outputs a category, followed by string data i.e. "Person: Bob"
 * *************/
void Menu::stringResult(std::string category, std::string result)
{
	std::cout << category << result << std::endl;
}

/****************
 * intResult
 * outputs a category, followed by an int data i.e. "Person: 1"
 * *************/
void Menu::intResult(std::string category2, int result)
{
	std::cout << category2 << result << std::endl;
}


/***************
 * doubleResult
 * outputs category, followed by data i.e. "Value: 6.3"
 * ************/
void Menu::doubleResult(std::string category3, double result)
{
	std::cout << category3 << result << std::endl;
}

/***************
 * getString
 * gets string from user and returns it
 * ************/
std::string Menu::getString(std::string instructions)
{
	std::cout << instructions << std::endl;
	std::string text;
	std::getline(std::cin,text);
	return text;
}
