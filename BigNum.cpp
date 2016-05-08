//Hanyu Zhang
#include "BigNum.h"
#include <iostream>

// in add operation, make first operand longer than second one 
bool BigNum::swap(vector<unsigned int> &a, vector<unsigned int> &b) {
	vector<unsigned int> temp;
	for (int i = 0; i < a.size() - 1;) {
		if (a[i] == 0) a.erase(a.begin());
		else break;
	}
	for (int i = 0; i < a.size() - 1;) {
		if (b[i] == 0) b.erase(b.begin());
		else break;
	}
	if (a.size() < b.size()) {
		temp = a;
		a = b;
		b = temp;
		return true;
	}
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > b[i]) break;
			if (a[i] < b[i])
			{
				temp = a;
				a = b;
				b = temp;
				return true;
			}
		}
	}
	return false;
}

string BigNum::add(vector<unsigned int> &a, vector<unsigned int> &b) {
	swap(a, b);                                               //make sure the first operand is longer than the second one
	int carry = 0;
	unsigned int thisDigit;
	vector<int> result;
	string output;
	for (int i = 0; i < a.size(); i++) {
		if (i < b.size()) {
			thisDigit = a[a.size() - 1 - i] + b[b.size() - 1 - i] + carry;
			result.push_back(thisDigit % 10);
			carry = thisDigit / 10;
		}
		else {
			thisDigit = a[a.size() - 1 - i] + carry;
			result.push_back(thisDigit % 10);
			carry = thisDigit / 10;
		}
	}
	if (carry == 1)
		result.push_back(carry);
	for (int i = 0; i < result.size(); i++) {
		output.push_back(result[result.size() - 1 - i] + '0');
	}
	return output;

}

string BigNum::minus(vector<unsigned int> &a, vector<unsigned int> &b) {
	bool sign = swap(a, b);                                //make sure the abs of first operand is greater than the second one
	int carry = 0;
	int thisDigit;
	vector<int> result;
	string output;
	for (int i = 0; i < a.size();i++) {
		if (i < b.size()) {
			thisDigit = a[a.size() - 1 - i] - b[b.size() - 1 - i] - carry;
			result.push_back((thisDigit + 10) % 10);
			carry = thisDigit < 0 ? 1 : 0;
		}
		else {
			thisDigit = a[a.size() - 1 - i] - carry;
			result.push_back((thisDigit + 10) % 10);
			carry = thisDigit < 0 ? 1 : 0;
		}
	}
	for (int i = 0; i < result.size() - 1; i++) {                      //get rid of consecutive 0 in high digits
		if (result.back() == 0) result.pop_back();
		else break;
	}
	for (int i = 0; i < result.size(); i++) {
		output.push_back(result[result.size() - 1 - i] + '0');
	}
	if (sign == true) return '-' + output;                         //if two operand has been swap return a '-'
	else return output;
}

string BigNum::times(vector<unsigned int> &a, vector<unsigned int> &b) {
	vector<int> layer;
	vector<int> result;
	int carry = 0;
	int thisDigit;
	int size;
	string output;
	for (int i = b.size() - 1; i >= 0;i--) {
		if (b[i] == 0) continue;
		for (int j = a.size() - 1; j >= 0; j--) {
			thisDigit = b[i] * a[j] + carry;
			layer.push_back(thisDigit % 10);
			carry = thisDigit / 10;
		}
		if (carry != 0) layer.push_back(carry);
		carry = 0;
		for (int k = 0; k < b.size() - 1 - i; k++) {                      //simulate times operation
			layer.insert(layer.begin(), 0);
		}
		if (layer.size() > result.size()) size = layer.size();
		else size = result.size();
		for (int k = 0; k < size;k++) {                                   //perhaps problem here!!
			if (k < result.size()) {
				thisDigit = result[k] + layer[k] + carry;
				result[k]=thisDigit % 10;
				carry = thisDigit / 10;
			}
			else {
				thisDigit = layer[k] + carry;
				result.push_back(thisDigit % 10);                         //extend result digits
				carry = thisDigit / 10;
			}
		}
		if (carry == 1) result.push_back(carry);
		layer.clear();
		carry = 0;
	}
	for (int i = 0; i < result.size(); i++) {
		output.push_back(result[result.size() - 1 - i] + '0');
	}
	return output;
}

//this is a very complicated one!!
string BigNum::divide(vector<unsigned int> &a, vector<unsigned int> &b) {
	vector<unsigned int> segment;
	vector<unsigned int> second1, second2;
	string temp1, temp2;
	string output;
	int counter = 0;
	temp1 = BigNum::minus(a, b);
	if (temp1[0] == '-') return "0";                                       //a is less than b, return

	bool equalength = true;                                                //whether the first high segment of a is greater than b
	//convert vector to string and reuse minus function!!
	for (int i = 0; i < b.size(); i++) {
		second1.push_back(b[i]);
	}
	//find when high segment of a is greater than b
	for (int i = 0; i < b.size(); i++) {
		if (a[i] < b[i]) {
			equalength = false;
			break;
		}
	}
	if (equalength == true) {
		for (int i = 0; i < b.size(); i++) {
			segment.push_back(a[i]);
		}
		for (int i = b.size() - 1;;) {
			while (1) {
				second2 = second1;
				temp1 = BigNum::minus(segment, second2);
				if (temp1[0] == '-') break;
				temp2 = temp1;
				counter++;
				segment.clear();
				for (int i = 0; i < temp2.length();i++) {
					segment.push_back(temp2[i] - '0');
				}
			}
			//output one digit and reset
			output.push_back(counter + '0');
			counter = 0;
			//connect mod and next digit of a
			segment.clear();
			for (int i = 0; i < temp2.length();i++) {
				segment.push_back(temp2[i] - '0');
			}
			i++;
			if (i >= a.size()) break;
			segment.push_back(a[i]);
			temp2.push_back(a[i] + '0');
			for (int i = 0; i < temp2.size() - 1;) {
				if (temp2[i] == '0') temp2.erase(temp2.begin());
				else break;
			}
		}
	}
	else {
		for (int i = 0; i < b.size() + 1; i++) {
			segment.push_back(a[i]);
		}
		for (int i = b.size();;) {
			while (1) {
				second2 = second1;
				temp1 = BigNum::minus(segment, second2);
				if (temp1[0] == '-') break;
				temp2 = temp1;
				counter++;
				segment.clear();
				for (int i = 0; i < temp2.length();i++) {
					segment.push_back(temp2[i] - '0');
				}
			}
			//output one digit and reset
			output.push_back(counter + '0');
			counter = 0;
			//connect mod and next digit of a
			segment.clear();
			for (int i = 0; i < temp2.length();i++) {
				segment.push_back(temp2[i] - '0');
			}
			i++;
			if (i >= a.size()) break;
			segment.push_back(a[i]);
			temp2.push_back(a[i] + '0');
			for (int i = 0; i < temp2.size() - 1;) {
				if (temp2[i] == 0) temp2.erase(temp2.begin());
				else break;
			}
		}
	}
	return output;
}

string BigNum::power(vector<unsigned int> &a, vector<unsigned int> &b) {
//use times function
	string process;
	string result;
	string counter;
	vector<unsigned int> temp;
	vector<unsigned int> loop;
	vector<unsigned int> one;
	one.push_back(1);
	for (int i = 0; i < a.size();i++) {
		result.push_back(a[i] + '0');
	}
	temp = a;
	loop = b;
	if (b.size() == 1 && b[0] == 1) return result;
	while (1) {
		result = BigNum::times(temp, a);
		temp.clear();
		for (int i = 0; i < result.length(); i++){
			temp.push_back(result[i] - '0');
		}
		counter = BigNum::minus(loop, one);
		if (counter == "1") break;
		loop.clear();
		for (int i = 0; i < counter.length(); i++) {
			loop.push_back(counter[i] - '0');
		}
	}
	return result;
}

string BigNum::mod(vector<unsigned int> &a, vector<unsigned int> &b) {
	vector<unsigned int> segment;
	vector<unsigned int> second1, second2;
	string temp1, temp2;
	string output;
	int counter = 0;
	temp1 = BigNum::minus(a, b);
	if (temp1[0] == '-') {                                                 //a is less than b, return
		for (int i = 0; i < b.size();i++) {
			temp2.push_back(b[i] + '0');
		}
		return temp2; 
	}
	
	bool equalength = false;                                               //whether the first high segment of a is greater than b
																		   //convert vector to string and reuse minus function!!
	for (int i = 0; i < b.size(); i++) {
		second1.push_back(b[i]);
	}
	//find when high segment of a is greater than b
	for (int i = 0; i < b.size(); i++) {
		if (a[i] > b[i]) {
			equalength = true;
			break;
		}
	}
	if (equalength == true) {
		for (int i = 0; i < b.size(); i++) {
			segment.push_back(a[i]);
		}
		for (int i = b.size() - 1;;) {
			while (1) {
				second2 = second1;
				temp1 = BigNum::minus(segment, second2);
				if (temp1[0] == '-') break;
				temp2 = temp1;
				counter++;
				segment.clear();
				for (int i = 0; i < temp2.length();i++) {
					segment.push_back(temp2[i] - '0');
				}
			}
			counter = 0;
			//connect mod and next digit of a
			segment.clear();
			for (int i = 0; i < temp2.length();i++) {
				segment.push_back(temp2[i] - '0');
			}
			i++;
			if (i >= a.size()) break;
			segment.push_back(a[i]);
			temp2.push_back(a[i] + '0');
			for (int i = 0; i < temp2.size() - 1;) {
				if (temp2[i] == '0') temp2.erase(temp2.begin());
				else break;
			}
		}
	}
	else {
		for (int i = 0; i < b.size() + 1; i++) {
			segment.push_back(a[i]);
		}
		for (int i = b.size();;) {
			while (1) {
				second2 = second1;
				temp1 = BigNum::minus(segment, second2);
				if (temp1[0] == '-') break;
				temp2 = temp1;
				counter++;
				segment.clear();
				for (int i = 0; i < temp2.length();i++) {
					segment.push_back(temp2[i] - '0');
				}
			}
			counter = 0;
			//connect mod and next digit of a
			segment.clear();
			for (int i = 0; i < temp2.length();i++) {
				segment.push_back(temp2[i] - '0');
			}
			i++;
			if (i >= a.size()) break;
			segment.push_back(a[i]);
			temp2.push_back(a[i] + '0');
			for (int i = 0; i < temp2.size() - 1;) {
				if (temp2[i] == '0') temp2.erase(temp2.begin());
				else break;
			}
		}
	}
	return temp2;
}
//input rule
/*
add operation: 
num1 
+ 
num2

minus operation: 
num1 
- 
num2

times operation: 
num1 
* 
num2

divide operation: 
num1 
/ 
num2

power operation: 
num1 
pow 
num2

mod operation: 
num1 
mod 
num2
*/
string BigNum::operationManager(string &a, const string &operation, string &b) {
	vector <unsigned int> first, second;
	string output;
	for (int i = 0; i < a.length(); i++) {
		if(a[i] >= '0' && a[i] <= '9')
			first.push_back(a[i] - '0');
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] >= '0' && b[i] <= '9')
			second.push_back(b[i] - '0');
	}

	//add
	if (operation == "+") {
		if (a[0] == '-' && b[0] != '-')
			output = BigNum::minus(second, first);
		else if (a[0] == '-' && b[0] == '-')
			output = '-' + BigNum::add(first, second);
		else if (a[0] != '-' && b[0] == '-')
			output = BigNum::minus(first, second);
		else
			output = BigNum::add(first, second);
	}
	//minus
	else if (operation == "-") {
		if (a[0] == '-' && b[0] != '-')
			output = '-' + BigNum::add(first, second);
		else if (a[0] == '-' && b[0] == '-')
			output = BigNum::minus(second, first);
		else if (a[0] != '-' && b[0] == '-')
			output = BigNum::add(first, second);
		else
			output = BigNum::minus(first, second);
	}
	//times
	else if (operation == "*") {
		if (a == "0" || b == "0")
			output == "0";
		else {
			if ((a[0] == '-' && b[0] != '-') || (a[0] != '-' && b[0] == '-')) {
				output = '-' + BigNum::times(first, second);
			}
			else
				output = BigNum::times(first, second);
		}
	}
	//divide
	else if (operation == "/") {
		if (b == "0")
			cout << "divisor cannot be 0!" << "\n";
		else {
			if ((a[0] == '-' && b[0] != '-') || (a[0] != '-' && b[0] == '-')) {
				output = '-' + BigNum::divide(first, second);
			}
			else
				output = BigNum::divide(first, second);
		}
	}
	//power
	else if (operation == "pow") {
		if (a == "0")
			output = "0";
		else if (b == "0")
			output = "1";
		else if (a[0] == '-') {
			if ((*(b.end() - 1) - 48) % 2 == 0) {
				output = BigNum::power(first, second);
			}
			else
				output = '-' + BigNum::power(first, second);
		}
		else output = BigNum::power(first, second);
	}
	//mod
	else if (operation == "mod") {
		if (b == "0" || b[0]=='-')
			cout << "divisor cannot be 0 or negative!" << "\n";
		else if (a[0] == '-') {
			output = '-' + BigNum::mod(first, second);
		}
		else
			output = BigNum::mod(first, second);
	}
	cout << output << endl;
	return output;
}
