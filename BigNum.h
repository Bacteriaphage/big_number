//Hanyu Zhang
#pragma once

#include <string>
#include <vector>
using namespace std;

class BigNum {
    
public:
    
    static string operationManager(string a, const string op, string b);

	static bool swap(vector<unsigned int> &a, vector<unsigned int> &b);

	static string add(vector<unsigned int> &a, vector<unsigned int> &b);

	static string minus(vector<unsigned int> &a, vector<unsigned int> &b);

	static string times(vector<unsigned int> &a, vector<unsigned int> &b);

	static string divide(vector<unsigned int> &a, vector<unsigned int> &b);

	static string power(vector<unsigned int> &a, vector<unsigned int> &b);

	static string mod(vector<unsigned int> &a, vector<unsigned int> &b);
    
    static string powerMod(string a, string n, string m);
};

std::string operator""_s (const char* cs, size_t);

string operator+(string a, string b);
string operator-(string a, string b);
string operator*(string a, string b);
string operator/(string a,string b);

string operator%(string a,string b);

string operator+(string a, int b);

string operator-(string a, int b);
string operator*(string a, int b);
string operator/(string a, int b);
string operator%(string a, int b);


bool operator> (string a, string b);

bool operator< (string a, string b);

bool operator> (string a, int b);

bool operator< (string a, int b);

bool operator== (string a, int b);
bool operator!= (string a, int b);

