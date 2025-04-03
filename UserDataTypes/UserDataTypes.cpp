// UserDataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Employee.h"
#include <iostream>
using namespace std;

int main() {
    int numEmployees;
    std::cout << "Number of employees (max 5): ";
    std::cin >> numEmployees;

    if (numEmployees > 5) numEmployees = 5; // Limit to 5 employees

    Employee employees[5]; // Array of Employee objects

    for (int i = 0; i < numEmployees; i++) {
        std::cout << "\nEnter details for Employee " << (i + 1) << ":\n";
        employees[i].Read();
    }

    std::cout << "\n--- Payroll Summary ---\n";
    for (int i = 0; i < numEmployees; i++) {
        employees[i].Write();
    }

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
