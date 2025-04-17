#pragma once

#include <iostream>

class Animal
{
public:

enum class eType
{
	CAT,
	DOG,
	BIRD
};

std::string name;
unsigned short age;

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

std::string GetName();
short GetAge();

virtual eType GetType() = 0;
};