#include "iostream"

// count length
int countLength(int x)
{
    int count = 0;

    while(x > 0)
    {
        count++;
        x = x/10;
    }
    return count;
}


bool isPalindrone(int x)
{
    int rev = 0;
    int original_number = x;

    while(x > 0)
    {
        int num = x%10;
        x = x/10;
        rev = rev * 10 + num;
    }

    if(original_number == rev)
        return true;
    return false;
}

/*------ Iterative solution------------
Time Complexity:- Thetha(n)
Auxiliary space complexity:- Thetha(1)
This solution is good than recursive solution */
int factorial(int x)
{
    int result = 1;

    while(x>1)
    {
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
    if (x == 0)
        return 1;   
    return (x * factorialRecursive(x-1));
}

int main()
{
    int test1 = factorialRecursive(6);
    std::cout << test1 << std::endl;

}