
#include <iostream>

int g = 10;

struct smart_prt
{
	int* p = nullptr;

	smart_prt(int* p) : p(p) {}
	~smart_prt() { delete p; }
};

int main()
{
	g = 23;

    int i = 5;
	int* p = &i;
	delete p;

	{
		int* ptr = new int(10);
		delete ptr;
	}
}
