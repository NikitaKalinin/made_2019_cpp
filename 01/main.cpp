#include "functions.h"


int main(int argc, char* argv[])
{
	int have_mult_div = 0;
	if (checking(argc, argv, &have_mult_div))
	{
		string result = calculate(argv, argc, have_mult_div).c_str();
		cout << result << endl;
		return (result == "Zero division") ? 1 : 0;
	}

	cout << "Bad request" << endl;
	return 1;
}
