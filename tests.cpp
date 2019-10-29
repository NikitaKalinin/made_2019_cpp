#include "ParseLibrary.h"
#include <iostream>
#include <cstring>
#include <vector>

int main()
{
	ParseLibrary parser;
	parser.SetInitialCall([]() {});
	parser.SetFinallCall([]() {});
	parser.SetCharCallBack([](std::string&) {});
	parser.SetIntCallBack([](int&) {});

	const char TestData[] = { '1', '2', '3', ' ','\n','\t', 'e','1','2', ' ', '5' };
	parser.ParseData(TestData,11);

	std::vector<int> testInts = parser.GetIntTokens();
	std::vector<std::string> testStrings = parser.GetCharTokens();

	std::cout << (testInts[0] == 123) << std::endl;
	std::cout << (testInts[1] == 5) << std::endl;
	std::cout << (testStrings[0] == "e12") << std::endl;

	return 0;
}