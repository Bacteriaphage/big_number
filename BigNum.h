//Hanyu Zhang
#pragma once

#include <string>
#include <vector>
using namespace std;

class BigNum {

public:

	static string operationManager(string &a, const string& op, string &b);

	static bool swap(vector<unsigned int> &a, vector<unsigned int> &b);

	static string add(vector<unsigned int> &a, vector<unsigned int> &b);

	static string minus(vector<unsigned int> &a, vector<unsigned int> &b);

	static string times(vector<unsigned int> &a, vector<unsigned int> &b);

	static string divide(vector<unsigned int> &a, vector<unsigned int> &b);

	static string power(vector<unsigned int> &a, vector<unsigned int> &b);

	static string mod(vector<unsigned int> &a, vector<unsigned int> &b);
};