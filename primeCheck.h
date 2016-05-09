//
//  primeCheck.h
//  bignumber
//
//  Created by Shaobo Liu on 5/4/16.
//  Copyright © 2016 Stevens Institute of Technology. All rights reserved.
//

#ifndef primeCheck_h
#define primeCheck_h

#include <string>
#include <time.h>
#include "BigNum.h"
using namespace std;

class primeCheck{
private:
    string a;
    bool isprime;
public:
    primeCheck(string a) : a(a){}
    void bruteForce(){
		if (a.size() > 10) {
			cout << "This number is too large to sieve!" << endl;
			return;
		}
		time_t start, end;
		start = clock();
        string one;
        one.push_back('1');
        for(string i = "2";i < a;i = BigNum::operationManager(i, "+", one)){
            string c = BigNum::operationManager(a, "mod", i);
            if(c=="0"){
                isprime = false;
				end = clock();
				cout << "NOT Prime" << "  time:" << double(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
				return;
            }
            
		}
		isprime = true;
		end = clock();
		cout << "Is prime" << "  time:" << double(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
		return;
    
}
    void seive(){
		time_t start, end;
		start = clock();
		if (a.size() > 10) {
			cout << "This number is too large to sieve!" << endl;
			return;
		}
        long long A = stoi(a);
        bool *index = new bool[A + 1];
        for(long long i = 0; i < A + 1; i++)
            index[i] = true;
        index[0] = index[1] = false;
        for(long long i = 2; i < A + 1; i++){
            for(long long j = i * i; j < A + 1; j = j + i){
                index[j] = false;
            }
        }
		end = clock();
		if (index[A] == true) cout << "Is prime" << "  time:" << double(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
		else cout << "NOT prime" << "  time:" << double(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
		
		return;
    }

};


#endif /* primeCheck_h */
