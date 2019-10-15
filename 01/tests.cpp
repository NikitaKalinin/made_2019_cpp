#include "functions.h"

int main(int argc, char* argv[])
{

	int have_mult_div = 0;
	if (checking(argc-1, argv, &have_mult_div))
	{
		string result = calculate(argv, argc-1, have_mult_div).c_str();
		if (abs(atof(&result[0]) - atof(argv[argc - 1])) < 0.001) 
		{
				cout << "good" << endl;
				return 0;
		}						
	}
	
	cout << "bad" << endl;
	return 0;
}
