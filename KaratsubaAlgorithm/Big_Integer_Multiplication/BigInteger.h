#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger
{
public:
	BigInteger();
	~BigInteger();
	int Max(int lenght1, int lenght2);
	string Add(string value1, string value2);
	string Subtract(string value1, string value2);
	string Multiply(string value1, string value2);
	string Readfile(string filename, int N);
	bool WriteFile(string result);
};

