#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <vector>
using namespace std;

bool checking(int argc, char* argv[], int* have_mult_div)
{
	regex regular_check("[\\-]{0,1}"
		"([0-9]+)"
		"\\s"
		"([\\-\\+\\/\\*])"
		"\\s"
		"[\\-]{0,1}"
		"([0-9]+)");
	if ((argc - 1) % 2 == 0) return false;
	if ((argc - 1) == 1) return regex_match(argv[1], regex("[\\-]{0,1}"
		"([0-9]+)"));
	for (int i = 1; i < argc - 2; i += 2)
	{
		stringstream ss;
		ss << argv[i] << ' ' << argv[i + 1] << ' ' << argv[i + 2];
		if ((argv[i + 1][0] == '/') || (argv[i + 1][0] == '*')) *have_mult_div += 1;
		if (!regex_match(ss.str(), regular_check)) return false;
	}
	return true;
}

string calc_expr(string a, string action, string b)
{
	float a_float = atof(a.c_str());
	float b_float = atof(b.c_str());
	switch (action[0])
	{
	case '*':
		return to_string(a_float * b_float);
	case '/':
	{
		if (b_float == 0)
			throw logic_error("Zero division");
		else
			return to_string(a_float / b_float);
	}
	case '+':
		return to_string(a_float + b_float);
	case '-':
		return to_string(a_float - b_float);
	}
}

string calculate(char* calc_command[], const int size, int have_mult_div)
{
	if (size > 2)
	{
		for (int i = 1; i < size - 2; i += 2)
		{
			if ((have_mult_div > 0) &&
				((calc_command[i + 1][0] == '+') || (calc_command[i + 1][0] == '-')))
				continue;
			string result;
			try
			{
				result = calc_expr(calc_command[i], calc_command[i + 1], calc_command[i + 2]);
			}
			catch (exception e)
			{
				return e.what();
			}
			char* out_command[size - 2];
			for (int j = 0; j < i; ++j)
			{
				out_command[j] = new char[(strlen(calc_command[j]))*sizeof(char)];
				out_command[j] = calc_command[j];
			}
			out_command[i] = new char[(result.length())*sizeof(char)];
			out_command[i] = &result[0];
			for (int j = i + 3; j < size; ++j)
			{
				out_command[j - 2] = new char[(strlen(calc_command[j]))*sizeof(char)];
				out_command[j - 2] = calc_command[j];
			}
			return calculate(out_command, size - 2, have_mult_div - 1);
		}
	}
	return calc_command[1];
}
