#include <iostream>

class Array
{
public:
    /**
     * @brief
     *
     * @param arr
     * @param n -> size of an array
     * @param x -> element which need to be delete
     * @return int -> size of an arr
     */
    int deleteEle(int arr[], int n, int x);

    /**
     * @brief 
     * 
     * @param arr 
     * @param n 
     * @return int 
     */
    int largestEle(int arr[], int n);

    // int largestElement(int arr[]);

    /**
     * @brief 
     * 
     * @param arr 
     * @param n 
     * @return index of second largest element
     */
    int secondLargestIndex(int arr[], int n);

    /**
     * @brief 
     * 
     * @param arr 
     * @param n 
     * @return true 
     * @return false 
     */
    bool isSorted(int arr[], int n);

    /**
     * @brief 
     * 
     * @param arr 
     * @param n 
     */
    void reverseArray(int arr[], int n);
};

int Array::deleteEle(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            break;
        }
    }
    if (i == n)
    {
        return n;
    }
    for (int j = i; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
    return n - 1;
}

int Array::largestEle(int arr[], int n)
{
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}

/**
//That's why always need to send array size in function argument.
// we only pass the arrays address in a function, compiler can not know the arrays size by looking at the address
int Array::largestElement(int arr[])
{
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}
**/

//Time complexity is O(n) - Best solution.
int Array::secondLargestIndex(int arr[], int n)
{
    int max = 0;
    int secondMax = -1;
    for(int i=0; i<n; i++)
    {
        if(arr[i] > arr[max])
        {
            secondMax = max;
            max = i;
        }
        else if(arr[i] != arr[max])
        {
            if(secondMax == -1 || arr[i] > arr[secondMax])
            {
                secondMax = i;
            }
        }
    }
    return secondMax;
}

bool Array::isSorted(int arr[], int n)
{
    for(int i=0; i < n-1; i++)
    {
        if(arr[i] <= arr[i+1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void Array::reverseArray(int arr[], int n)
{
    // if(n%2==0)
    // {
    //     int iteration = n/2;
    // }
    // else
    // {
    //     int iteration = (n-1)/2;
    // }

    // for(int i=0; i < iteration; i++)
    // {
    //     int temp = arr[i];
    //     arr[i] = arr[n-1-i];
    //     arr[n-1-i] = temp;
    // }
    int low = 0;
    int high = n-1;
    while(low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

int main()
{
    int arr[] = {10,19,45,20,23,78};
    int testcase[] = {2,3,4,5,5,3,6};
    Array arrObj;
    std::cout << "Checking of larget Element in arr " << arrObj.largestEle(arr,(sizeof(arr)/sizeof(arr[0]))) << std::endl;
    // std::cout << "Checking of larget Element in arr without n" << arrObj.largestElement(arr) << std::endl; //not give desired result
    std::cout << "SecondLargetIndex " << arrObj.secondLargestIndex(testcase,(sizeof(testcase)/sizeof(testcase[0]))) << std::endl;
    std::cout << "isSorted " << arrObj.isSorted(testcase,(sizeof(testcase)/sizeof(testcase[0]))) << std::endl;
}