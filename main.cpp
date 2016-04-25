#include "BigNum.h"
#include <iostream>
int main() {
	string first;
	string second;
	string operation;
	while (1) {
		cin >> first;
		cin >> operation;
		cin >> second;
		BigNum::operationManager(first, operation, second);
	}
}