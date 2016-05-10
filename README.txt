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

Part2 primetest(Author: Yunfei Lu, Shaobo Liu)

The primeCheck class uses four methods to check big prime numbers. 
The four methods are :
i. brute force methods 
ii. Eratosthenes’ sieve
iii. Fermat
iv. Miller­Rabin
These four methods all implement the BigNum.h for a big number. We using string instead of int to use these methods. We
also add a CLOCK to calculate  the time and compare which one uses less time. 

Brute force :
We start with 2 , when n mod==0, it is not  a prime number.  Otherwise, it is a prime number. The clock calculate the time
when this method finished.

Eratosthenes’ sieve :
We build a boolean array, with size of A+1. At the beginning, we set every elements to true. We use i start from a the 2,
the every j start from i*i , adding i each time(less than A+1), is not a prime.

Fermat:
Fermat primality test is based on the formula: a^(n-1) % n = 1. a is the number between [2, n -2]. If the formula comes
true, then we can see n is possibly prime. Our function is Fermat(string n, int k). This method has two arguments, the
number n is which you want to check and the k is iteration time you want to run to make sure the correctness. Since for
each loop it has 50% possibility to find out composite (not Carmichael numbers), we can set k = 10, then the possibility
would be very close to 100%. The flaw of this algorithm is if we randomly choose an a which is coprime to n(which is
Carmichael numbers), then this Carmichael numbers(actually not prime) will pass the test. There are infinite Carmichael
numbers, thus this algorithm is not robust.

Miller-rabin:
Miller-rabin is based on the formula:  a^(n-1) % n = 1. But the difference between miller-rabin and fermat is miller-rabin
is robust to Carmichael numbers and they have same time complexity.
 
random number generator:
Since the first step of miller-rabin and fermat is to pick up a random number between [2, n-2]. However, the given random
number generator doesn't provide such long numbers. Thus, we build our own random number generator which provide random
numbers in the range you set. The random number is not well distributed, but it's enough for our purpose.
