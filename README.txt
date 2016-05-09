Prime test based on Big Number library
**************************************
Authors
**************************************

Hanyu Zhang

Shaobo Liu

Yunfei Lu

**************************************
Introduction
**************************************
This project can compare time consumption of four prime test method including brute force, sieve, Miller-Rabin, Fermat. The number can be bigger than 2^64 because we have a big number library. All input number are stored as string and before operation, they will be transfered to vector.

**************************************
Instruction
**************************************
Part1 BigNum library(Author: Hanyu Zhang)

This library contain 6 big number operations: +, -, *, /, power, mod

2 auxiliary methods: swap(), operationManager()

swap()

This method is used to swap two operand when they do add and minus operation. If the abs value of the first operand is greater than that of the second operand, they will be swapped.

operationManager()

This method can get two operands(string) and an operator from interface and decides which operation method will be used. It also preprocesses operation such as string to vector transformaiton, sign calculation, 0 check, etc.

add()
This method is used to calculate the sum of two operand. After swap, add every digit of the greater one to the other operand, calculate carry and add the carry to next add digit operation.

minus()
This method is used to calculate minus operation of two operands. It is similar with add().

times()
This method simulate manual times operation, I calculate the result of every digits of second operand times whole first operand, and add the together after shifting. 

divide()
This method simulate manual divide operation, I choose a number which greater than the second operand from high digits of first operand, and minus it with second operand. I use a counter to count how many times the result will be 0 or negative. After the result is 0 or negative push back counter to divide vector and push back the next digit of the first operand to mod of the last remainder, then do minus again. When all digits of the first operand is processed, transfer divide vector to string and return.

power()
This method uses times() repeatedly and use minus() to minus counter.

mod()
This method is similar with divide() but output last remainder of divide operation.



 