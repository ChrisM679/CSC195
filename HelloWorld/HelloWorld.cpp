// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Student.h"
#include <iostream>

using namespace std;

class Person
{
public:
    std::string name;
    int age;

    void f();
};

int main() {

    Student student;
    student.SetName("Chris");
    student.Write();
    f();

    Person person;
    person.age = 19;

    unsigned int i = 82;
    //printf("%d\n", i);
    std::cout << i << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(Person) << std::endl;

    cout << ++i << endl;

    char c = 'A';

    cout << &i << endl;

    cout << "Hello, World!" << endl;
    cout << "Git is now tracking this project!" << endl;

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
