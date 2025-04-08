#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <map>

using namespace std;

int main()
{
	//array
	array<string, 7> arr = {"Monday","tusday","Wensday","Thursday","Friday","Saturday","Sunday"};
	cout << arr.size() << endl;

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}

	cout << endl;

	//vector
	vector<int> vec = { 1,2,3,4,5 };
	vec.push_back(6);
	vec.push_back(7);
	vec.pop_back();

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}

	cout << endl;

	//list
	list<string> lst = {"Apple", "Orange", "Grape"};
	lst.insert(lst.begin(), "Watermellon");
	lst.insert(lst.end(), "Bananas");
	lst.remove("Grape");

	for (list<string>::iterator it = lst.begin(); it != lst.end(); ++it) {
		cout << *it << " ";
	}

	cout << endl;

	//map
	map<string, int> m;
	m["apples"] = 46;
	m["bananas"] = 86;
	m["Orange"] = 100;
	m["bananas"] = 98;

	for (const auto& fruit : lst) {
		cout << fruit << " ";
	}

	return 0;
}