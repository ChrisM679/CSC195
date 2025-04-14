// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Human.h"


int main()
{
	{
		Human human1;
		Human human2;
		Human human3;

		std::cout << Human::GetCount() << std::endl;
	}

	std::cout << Human::GetCount() << std::endl;
}

