#pragma once
#include <string>

void f();

class Student
{
public:
	Student() {}
	Student(std::string name) { this->m_name = name; }

	void Write();
	std::string GetName() { return m_name; }
	std::string SetName(std::string name) { m_name = name; }

private:
	std::string m_name;
};