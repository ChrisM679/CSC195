#pragma once
#include "Animal.h"
#include <iostream>

class Cat : public Animal
{
public:

	virtual void Read()
	{
		std::cout << "Name";
		std::cin >> name;
		std::cout << "Age";
		std::cin >> age;
	}
	virtual void Write()
	{
		std::cout << "Name" << std::endl;
		std::cout << "Age" << std::endl;
	}
};
