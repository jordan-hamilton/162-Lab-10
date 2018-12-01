#include "fibonacci.hpp"

/*************************************************************************
** Description: Takes a constant reference to a long long int, then
** performs a for loop to increment an integer, currentNumber, by the
** previous number in the loop, looping until the integer passed to the
** function is reached. The currentNumber variable is then returned as the
** desired Fibonacci number.
** Source: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
*************************************************************************/
long long int fibonacciNonRecursive(const int &n) {

  long long int currentNumber = 1;
  long long int prevNumber = 1;

  if (n <= 1) {
    return 1;
  } else {

    for (int i = 2; i < n; i++) {

        long long int temp = currentNumber;
        currentNumber = currentNumber + prevNumber;
        prevNumber = temp;

    }

    return currentNumber;

  }

}


/*************************************************************************
** Description: Takes a constant reference to a long long int, then calls
** the same function with the previous two numbers in the sequence. The
** calls repeat recursively until the passed number is less than or equal
** to 1 and return the calculated value.
** Source: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
*************************************************************************/
long long int fibonacciRecursive(const int &n) {

  if (n <= 1){
    return n;
  } else {
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
  }

}
