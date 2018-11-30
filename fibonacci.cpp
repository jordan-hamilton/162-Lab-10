//Source: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

#include "fibonacci.hpp"

using std::cout;
using std::endl;

int fibonacciNonRecursive(const int &n) {

  int currentNumber = 1;
  int prevNumber = 1;

  if (n <= 1) {
    return 1;
  } else {

    for (int i = 2; i < n; i++) {

        int temp = currentNumber;
        currentNumber = currentNumber + prevNumber;
        prevNumber = temp;

    }

    return currentNumber;

  }

}

int fibonacciRecursive(const int &n) {

  if (n <= 1){
    return n;
  } else {
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
  }

}
