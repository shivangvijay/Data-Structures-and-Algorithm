#include "iostream"

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

bool Palindrone(int x)
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

int main()
{
    bool test1 = Palindrone(123431);
    std::cout << test1 << std::endl;
}