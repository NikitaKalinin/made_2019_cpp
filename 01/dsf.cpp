#include <string>
#include <iostream>
using namespace std;

int main()
{
	char** a = new char*;
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << a[i];
	}
	return 0;
}
