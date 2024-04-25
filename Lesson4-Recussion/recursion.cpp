#include <iostream>
#include <cmath>
#include <string.h>

// tail recursion
void printNto1(int n)
{
  if (n == 0) {
    return;
  }
  std::cout << n << std::endl;
  printNto1(n - 1);
}

// Not a tail recusion
void print1toN(int n)
{
  if (n == 0) {
    return;
  }
  print1toN(n - 1);
  std::cout << n << std::endl;
}

int nFact(int n)
{
  if (n == 0) {
    return 1;
  }
  return n * nFact(n - 1);
}

int nFibNumber(int n)
{
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
  return nFibNumber(n - 1) + nFibNumber(n - 2);
}

int sumOfNaturalNumber(int n)
{
  if (n == 0) {
    return 0;
  }
  return n + sumOfNaturalNumber(n - 1);
}

int sumOfDigits(int n, int k)
{
  if (n == 0) {
    return k;
  }
  return sumOfDigits(n / 10, k + (n % 10));
}

int sumOfDigits(int n)
{
  if (n == 0) {
    return 0;
  }
  return sumOfDigits(n / 10) + (n % 10);
}

int main()
{
  int k = sumOfDigits(14311234);
  std::cout << k << std::endl;
}
