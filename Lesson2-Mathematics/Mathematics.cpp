#include <iostream>
#include <cmath>

// count length
int countLength(int x)
{
  int count = 0;

  while (x > 0) {
    count++;
    x = x / 10;
  }
  return count;
}


bool isPalindrone(int x)
{
  int rev = 0;
  int original_number = x;

  while (x > 0) {
    int num = x % 10;
    x = x / 10;
    rev = rev * 10 + num;
  }

  if (original_number == rev) {
    return true;
  }
  return false;
}

/*------ Iterative solution------------
Time Complexity:- Thetha(n)
Auxiliary space complexity:- Thetha(1)
This solution is good than recursive solution */
int factorial(int x)
{
  int result = 1;

  while (x > 1) {
    result = result * x;
    x = x - 1;
  }
  return result;
}


/*-----------Recussive solution------------
Time Complexity:- T(n) = T(n-1) + thetha(1) => Thetha(n)
Auxiliary space complexity:- Thetha(n)
This solution is bad than Iterative solution */
int factorialRecursive(int x)
{
  if (x == 0) {
    return 1;
  }
  return x * factorialRecursive(x - 1);
}

/* No Over flow issues, Also below is mine solution,
Please look website to look greeks for greeks solution.
Time complexity is O(logn)*/
int trailingZerosInFactorial(int n)
{
  int k = -1;
  int count = 0;
  int loop_count = 1;
  while (k != 0) {
    k = n / pow(5, loop_count);
    count = count + k;
    loop_count = loop_count + 1;
  }

  return count;

}

// gcd(x,y) == gcd(x-y,y) , y is smaller
// Below is my implementation
int GCD(int x, int y)
{
  int k = -1;
  k = std::min(x, y);
  x = std::max(x, y);
  y = k;

  while (x != y) {
    k = std::min(x, y);
    x = std::max(x, y);
    x = x - k;
    y = k;
  }

  return x;
}

int gcdGreek(int x, int y)
{
  while (x != y) {
    if (x > y) {
      x = x - y;
    } else {
      y = y - x;
    }
  }
  return x;
}

// time complexity is log(min(x,y)), better than above GCD methods
int optimizedGCD(int x, int y)
{
  if (y == 0) {
    return x;
  }
  return optimizedGCD(y, x % y);
}


// Time Complexity is O(sqrt(a))
// we can make it more efficient by checking that number is divisible by 2 and 3 in statrting
// and increment the loop by (+6) and start with 5. [Check website]
bool isPrime(int a)
{

  if (a == 1) {
    return false;
  }

  int sqrt_a = sqrt(a);
  for (int i = 2; i <= sqrt_a; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}

// prime factors - efficient method
// my method
void primeFactors(int a)
{
  int sqrt_a = sqrt(a);
  for (int i = 2; i <= sqrt_a; i++) {
    if (a == 1) {
      break;
    }
    if (isPrime(i)) {    // No need of it.
      while (a % i == 0) {
        std::cout << i << std::endl;
        a = a / i;
        if (isPrime(a)) {
          std::cout << a << std::endl;
        }
      }
    }
  }
}

// Time Complexity is O(sqrt(a))
// we can make it more efficient by checking that number is divisible by 2 and 3 in statrting
// and increment the loop by (+6) and start with 5. [Check website]
void primeFactorsGreek(int a)
{
  if (a == 1) {
    return;
  }

  int sqrt_a = sqrt(a);
  for (int i = 2; i <= sqrt_a; i++) {
    while (a % i == 0) {
      std::cout << i << std::endl;
      a = a / i;
    }
  }
  if (a > 1) {
    std::cout << a << std::endl;
  }
}

// Time Complexity is O(sqrt(a))
// check for sorted order print of divisor, you need two loop on addition.
void divisor(int a)
{
  for (int i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      std::cout << i << std::endl;
      if (i != a / i) {
        std::cout << a / i << std::endl;
      }
    }
  }
}


// H.W write both Iterative and Recursive solution with O(log(n))
int power(int a, int b)
{
  if (b % 2 == 0) {
    return power(a, b / 2)
  }
}


int main()
{
  divisor(25);
//   std::cout << test1 << std::endl;
}
