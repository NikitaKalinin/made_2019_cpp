#include <iostream>
#include <cstring>
#include <vector>
#include "ParseLibrary.h"

int main()
{
	auto charfunc = [](std::string& token) {std::cout << "get char token " << token << std::endl; };
	auto intfunc = [](int& token) {std::cout << "get int " << token << std::endl; };
	auto finallCall = []() {std::cout << "thats all" << std::endl; };
	auto startCall = []() {std::cout << "begin parse" << std::endl; };

	ParseLibrary parser;
	parser.SetCharCallBack(charfunc);
	parser.SetIntCallBack(intfunc);
	parser.SetInitialCall(startCall);
	parser.SetFinallCall(finallCall);

	const char data[10] = { 'a','d','\t','r', '1', ' ', '1','2','\n','3' };
	parser.ParseData(data, 10);

	std::vector<int> intData = parser.GetIntTokens();
	std::vector<std::string> charData = parser.GetCharTokens();

	for (int i = 0; i < intData.size(); ++i) std::cout << intData[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < charData.size(); ++i) std::cout << charData[i] << " ";

	return 0;
}
