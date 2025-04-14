#pragma once
#include <iostream>

class Human
{
public:
	Human()
	{
		std::cout << "Constructor\n ";
		m_count++;
	}

	Human(std::string name, unsigned short age) : m_name(name), m_age(age)
	{
		std::cout << "Constructor\n ";
		m_count++;
	}

	~Human()
	{
		std::cout << "Destructor\n";
		m_count--;
	}

	static int GetCount() { return m_count; }

private:
	std::string m_name;
	unsigned short m_age = 0;
	static int m_count;
	static float tax;
};