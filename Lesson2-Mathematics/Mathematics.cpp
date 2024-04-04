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

int main()
{
  int test1 = GCD(18, 3);
  std::cout << test1 << std::endl;
}
