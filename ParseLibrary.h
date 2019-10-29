#ifndef PARSELIBRARY_H
#define PARSELIBRARY_H

#include <iostream>
#include <cstring>
#include <vector>

class ParseLibrary
{
private:
	std::vector<int> IntTokens;
	std::vector<std::string> CharTokens;
	void (*InitialCall)() = nullptr;
	void (*IntCallback)(int&) = nullptr;
	void (*CharCallBack)(std::string&) = nullptr;
	void (*FinallCall)() = nullptr;
	bool CheckCallBacks();
public:
	ParseLibrary() = default;
	~ParseLibrary() = default;
	ParseLibrary(const ParseLibrary&) = delete;
	ParseLibrary(const ParseLibrary&&) = delete;
	ParseLibrary& operator= (const ParseLibrary&) = delete;
	ParseLibrary&& operator= (const ParseLibrary&&) = delete;

	void SetInitialCall(void (*initFunc)()) { InitialCall = initFunc; }
	void SetFinallCall(void (*finFunc)()) { FinallCall = finFunc; }
	void SetCharCallBack(void (*charFunc)(std::string&)) { CharCallBack = charFunc; }
	void SetIntCallBack(void (*intFunc)(int&)) { IntCallback = intFunc; }
	void ParseData(const char* data, const int size);
	std::vector<int> GetIntTokens() { return IntTokens; }
	std::vector<std::string> GetCharTokens() { return CharTokens; }
};

#endif
