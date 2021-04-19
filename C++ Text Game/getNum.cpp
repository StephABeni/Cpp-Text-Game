/*****************************
 * Author: Stephanie Benamati (Catlett)
 * Date: 9/29/2019
 * Description: Validates user input as an integer
*****************************/
#include <iostream>
#include <string>
#include "getNum.hpp"

/*adapted from post by Alex (March 25, 2008) at https://www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/ on 10/2/2019 */
//validates integers
int getInt()
{
	int num;
	bool fail;
	
	do
	{
		std::cin >> num;//ask for input
		
		//Succeed conditions first
		if(!(std::cin.fail())) //if extraction succeeds
		{
			fail=false;
		}
		if(fail==false)
		{
			std::cin.ignore(1000, '\n'); //ignore bad input
			if(std::cin.gcount() > 1) //if more than 1 spot ignored
			{
				fail=true;	
			}
		}
		
		//Failing conditions test
		if (std::cin.fail()) //if extraction fails
		{
			fail=true;
			std::cin.clear(); //reset operation to normal
			std::cin.ignore(1000, '\n'); //ignore bad input
		}

		if (fail==true)
		{
			std::cout << "Oops! That's not an integer. Please try again" << std::endl; //let user know error
		}
	
	}while (fail==true);
	

	return num;
}



/*******************
 * getDouble
 * validates doubles
 * *****************/
/*adapted from post by lastchance (10/17/2017) at http://www.cplusplus.com/forum/general/223147/ on 10/26/2019*/

double getDouble()
{
	double number;
	bool failed;

	do
	{
		std::cin >> number;//ask for input
		
		if(!(std::cin.fail())) //if extraction succeeds
		{
			failed=false;
			std::string test;
			std::getline(std::cin, test);
			if(test.find_first_not_of( " " ) != std::string::npos)
			{
				failed=true;
			}	
		}
		
		if (std::cin.fail()) //if extraction fails
		{
			failed=true;
			std::cin.clear(); //reset operation to normal
			std::cin.ignore(1000, '\n'); //ignore bad input
		}

		if (failed==true)
		{
			std::cout << "Oops! That is not a double. Please try again." << std::endl;
		}

	}while (failed==true);

	return number;
}


