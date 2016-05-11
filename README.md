#Prime test based on Big Number library
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

swap() complexity:O(log(n)) n is the value of operand

This method is used to swap two operand when they do add and minus operation. If the abs value of the first operand is greater than that of the second operand, they will be swapped.

operationManager()

This method can get two operands(string) and an operator from interface and decides which operation method will be used. It also preprocesses operation such as string to vector transformaiton, sign calculation, 0 check, etc.

vector transformation: Because my input number is stored as string form and it`s hard to do some math on char based number so that I translate pick every digit in string and push it to a int vector. 

negative sign calculation: It is hard to implement different operation to vector with sign, so it is very necessary to calculate unsignned vector first then decide whether the result is negative or not. In "+", "*", "/", we can figure out the sign easily but in "-" it is a little bit hard to do.

0 check: 0 check can make program relible and efficient. In multiplication if any operand is 0 the result is 0. In divide operation if the second operand is 0, we should not call divide() function.

add() O(log(n))
This method is used to calculate the sum of two operand. After swap, add every digit of the greater one to the other operand, calculate carry and add the carry to next iteration. Push back results of each iteration into result vector, after the iteration has finished, translate int vector to string and return.

minus() O(log(n))
This method is used to calculate minus operation of two operands. It is similar with add(). However, If swap() function has swap two operands, the result should be negative, so minus() function need to get a value from swap() function to figure out whether the output is negative. If the result is negative I add a "-" to the front of final output string.

There is another key in minus() function. After we get the result, it is possible for the result to have one or more 0 at the beginning. Thus we need erase begin if it is 0. The amount of digits we should erase will not exceed N-1, N is the number of digits the greater operand has, or we likely to get a empty output because of the result is 0;  

times() O(log(n) * log(n))
This method simulate manual times operation, I calculate the result of every digits of second operand times whole first operand, and add the together after shifting. 

divide() O(log(n) * log(n))
This method simulate manual divide operation, I choose a number which greater than the second operand from high digits of first operand, and minus it with second operand. I use a counter to count how many times the result will be 0 or negative. After the result is 0 or negative push back counter to divide vector and link the next digit of the first operand to remainder of the last minus operation, then do minus again. When all digits of the first operand is processed, transfer divide vector to string and return.

power() O(log(n) * log(n) * log(n))
This method uses times() repeatedly and use minus() to minus counter.

mod() O(log(n) * log(n))
This method is similar with divide() but output last remainder of divide operation.(However it is more difficult than divide operation)






Part2 primetest(Author: Yunfei Lu, Shaobo Liu)

The primeCheck class uses four methods to check big prime numbers. 
The four methods are :
i. brute force methods 
ii. Eratosthenes’ sieve
iii. Fermat
iv. Miller-Rabin
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

Fermat and Miller-rabin is very fast, after test, it can deal with 44 digits number using only 1 second, because complexity
of fermat and Miller-rabin is O(log(n)) and complexity of big number powermod is O(log(n) * log(n) * log(n)).
 
random number generator:
Since the first step of miller-rabin and fermat is to pick up a random number between [2, n-2]. However, the given random
number generator doesn't provide such long numbers. Thus, we build our own random number generator which provide random
numbers in the range you set. The random number is not well distributed, but it's enough for our purpose.






Part3 test interface(Author: Hanyu Zhang)

After encapsulation, the program can do both functions above, users type "primetest" or "bignumber" to tell the system which function they need.

In primetest interface, users only need to type which number they want to check. If the number has more than 9 digits, system will not output
test result from brute-force and sieve because they are too slow.

In bignumber interface, users need input 2 operands and 1 operator. The formats of operators are +, -, *, /, pow, mod.
