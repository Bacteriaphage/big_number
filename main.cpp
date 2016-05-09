#include "BigNum.h"
#include <iostream>
#include <random>
#include <limits>
#include <ctime>
#include "primeCheck.h"

class Prime {
public:
    static bool millerRabinTest(string, int);  
};


bool Prime::millerRabinTest(string n, int numberOfTrial) {
    string s = "0";
    string temp = n - "1"_s;
    bool ifContinue = true;
    if (n % "2"_s == "0" && n != "2") {
        return false;
    }
    else if (n == "2") return true;
    
    else {
        while (temp%"2"_s == "0") {
            s = s + "1"_s;
            temp = temp / "2"_s;
        }
        srand(0);
        for (int i = 0; i < numberOfTrial; i++) {
//            int random = rand();
//            string randomA = std::to_string(random);
//            % (n - 3) + 2;
            string randomA;
            if (n < to_string(numeric_limits<int>::max())) {
                int number = std::stoi( n - "3"_s );
                
                int random = rand() % number + 2;
                randomA = to_string(random);
                
            }
            else {
                randomA = to_string(rand() % (numeric_limits<int>::max() - 3) + 2);
            }
//            string x = BigNum::operationManager(randomA, "pow", temp);
//            x = x % n;
            string x = BigNum::powerMod(randomA, temp, n);
            if (x == "1" || x == n - "1"_s) {
                continue;
            } else {
                for (string j = "0"; j < s - "1"_s; j = j + "1"_s) {
//                    x = x * x % n;
                    x = BigNum::powerMod(x,"2",n);
                    if (x  == "1") {
                        return false;
                    }else if( x == n - "1"_s) {
                        ifContinue = false;
                        break;
                    }
                }
                if (ifContinue) {
                    return false;
                }
            }
        }
        return true;

    }
}

int main() {
	string func;
	while (1) {
		cout << "Please input the instruction:";
		cin >> func;
		if (func == "primetest") {
			string number;
			cout << "Please input the number:";
			cin >> number;
			cout << Prime::millerRabinTest(number, 5) << endl;
			primeCheck num(number);
			num.bruteForce();
			num.seive();
		}
		else if (func == "bignumber") {
			string first, second, operation;
			cout << "please input first number:";
			cin >> first;
			cout << "please input second number:";
			cin >> second;
			cout << "please input operator:";
			cin >> operation;
			cout << BigNum::operationManager(first, operation, second) << endl;
		}
		else {
			cout << "invalid input please choose a instruction again!" << endl;
		}
	}
    return 0;
    
}