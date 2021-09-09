#include "pch.h"
#include "txtData.h"


txtData::txtData()
{
}


txtData::~txtData()
{
}

HRESULT txtData::init()
{

	return S_OK;
}

void txtData::release()
{
}

void txtData::txtSave(const char* saveFileName, vector<string> vStr)
{
	HANDLE file;
	DWORD write;

	char str[2048];

	strncpy_s(str, 2048, vectorArrayCombine(vStr), 2046);

	file = CreateFile(saveFileName, GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, 2048, &write, NULL);

	CloseHandle(file);
}

char* txtData::vectorArrayCombine(vector<string> vArray)
{
	char str[256];
	ZeroMemory(str, sizeof(str));
	//100,100,80,100
	for (int i = 0; i < vArray.size(); ++i)
	{
		strncat_s(str, 256, vArray[i].c_str(), 254);
		if (i + 1 < vArray.size()) strcat_s(str, ";");
	}

	return str;
}

vector<string> txtData::txtLoad(const char * loadFileName)
{
	HANDLE file;
	DWORD read;

	char str[2048];

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 2048, &read, NULL);

	CloseHandle(file);

	//100,100,80,100
	return charArraySeparation(str);
}

vector<string> txtData::charArraySeparation(char charArray[])
{
	vector<string> vArray;
	char* temp;
	const char* seperator = ";";
	char* token;

	token = strtok_s(charArray, seperator, &temp);
	vArray.push_back(token);

	while (NULL != (token = strtok_s(NULL, seperator, &temp)))
	{
		vArray.push_back(token);
	}

	return vArray;
}
