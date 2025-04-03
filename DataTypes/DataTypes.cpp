// DataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	const float TAX = 0.1f; // 10% tax rate

	string name;
	char initial;
	int age;
	bool isAdult;
	int zipcode;
	float wage;
	int daysWorked;
	float hoursWorkedPerDay[7] = { 0 };

	cout << "Enter first name: ";
	cin >> name;

	cout << "Enter initial of last name: ";
	cin >> initial;

	cout << "Enter age: ";
	cin >> age;
	isAdult = (age >= 18);  // Determine adulthood status

	cout << "Enter zipcode: ";
	cin >> zipcode;

	cout << "Enter hourly wage: ";
	cin >> wage;

	cout << "Enter number of days worked (max 7): ";
	cin >> daysWorked;

	float totalHours = 0; // Initialize total hours to 0

	for (int i = 0; i < daysWorked; i++) {
		cout << "Enter hours worked for day " << (i + 1) << ": ";
		cin >> hoursWorkedPerDay[i];

		totalHours += hoursWorkedPerDay[i];  // Accumulate total hours
	}

	float grossIncome = totalHours * wage;
	float taxAmount = grossIncome * TAX;
	float netIncome = grossIncome - taxAmount;

	cout << "\nEmployee Payroll Summary\n";
	cout << "-------------------------\n";
	cout << "Name: " << name << " " << initial << ".\n";
	cout << "Age: " << age << " (Adult: " << (isAdult ? "Yes" : "No") << ")\n";
	cout << "Zipcode: " << zipcode << "\n";
	cout << "Hourly Wage: $" << wage << " per hour\n";
	cout << "Total Hours Worked: " << totalHours << " hours\n";
	cout << "Gross Income: $" << grossIncome << "\n";
	cout << "Tax Amount: $" << taxAmount << "\n";
	cout << "Net Income: $" << netIncome << "\n";
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
