#include "ParseLibrary.h"

void ParseLibrary::ParseData(const char* data, const int size)
{
	int IntToken = 0, CharSize = 0, CharCapacity = 10;
	bool MayBeInt = true;
	char* CharToken = new char[10];

	InitialCall();

	for (int i = 0; i < size; i++)
	{
		bool isSplit = ((data[i] != ' ') &&
			(data[i] != '\t') &&
			(data[i] != '\n'));

		if (isSplit)
		{
			CharToken[CharSize++] = data[i];
			if (isdigit(data[i]) && MayBeInt)
				IntToken = IntToken * 10 + (int)data[i] - 48;
			else
				MayBeInt = false;
			if (2 * CharSize > CharCapacity)
			{
				char* biggerCharToken = new char[CharCapacity *= 2];
				memcpy(biggerCharToken, CharToken, CharSize);
				delete[] CharToken;
				CharToken = biggerCharToken;
			}
		}

		if ((!isSplit || (i == size - 1)) && (CharSize > 0))
		{
			if (MayBeInt)
			{
				IntTokens.push_back(IntToken);
				IntCallback(IntToken);
			}
			else
			{
				std::string toToken(CharToken, CharSize);
				CharTokens.push_back(toToken);
				CharCallBack(toToken);
			}
			delete[] CharToken;
			CharToken = new char[10];
			CharCapacity = 10;
			CharSize = IntToken = 0;
			MayBeInt = true;
		}
	}
	FinallCall();
}