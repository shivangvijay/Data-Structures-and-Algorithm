#include <iostream>
#include <vector>

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

    /**
     * @brief
     *
     * @param arr
     * @param n
     * @return true
     * @return false
     */
    void moveZeroToEnd(int arr[], int n);

    /**
     * @brief
     *
     * @param arr
     * @param n
     */
    void leftRotate(int arr[], int n);

    /**
     * @brief 
     * 
     * @param arr 
     * @param n 
     * @param D 
     */
    void leftRotateDplace(int arr[], int n, int D);

    /**
     * @brief 
     * 
     * @param arr 
     * @param n 
     */
    void leader(int arr[], int n);

    /**
     * @brief 
     * 
     * @param arr 
     * @param n 
     */
    void leader2(int arr[], int n);
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
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
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

// Time complexity is O(n) - Best solution.
int Array::secondLargestIndex(int arr[], int n)
{
    int max = 0;
    int secondMax = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[max])
        {
            secondMax = max;
            max = i;
        }
        else if (arr[i] != arr[max])
        {
            if (secondMax == -1 || arr[i] > arr[secondMax])
            {
                secondMax = i;
            }
        }
    }
    return secondMax;
}

bool Array::isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
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
    int high = n - 1;
    while (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

// Important
void Array::moveZeroToEnd(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            std::swap(arr[i], arr[count]);
            count++;
        }
    }
}

void Array::leftRotate(int arr[], int n)
{
    int start = arr[0];
    for(int i=0; i<n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1] = start;
}

// if D > n then take factor of division.
// There are other 3 more methods in which 2 are more efficent. Look on it
void Array::leftRotateDplace(int arr[], int n, int D)
{
    int tempArr[n] = {0};
    for(int i=0; i<n; i++)
    {
        if(i<D)
        {
            tempArr[n+(i-D)] = arr[i];
        }
        else
        {
            tempArr[i-D] = arr[i];
        }
    }

    for(int i=0; i<n; i++)
    {
        arr[i] = tempArr[i];
    }
}

//this method requires thetha(n^2)
void Array::leader(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int j; //one flag method too is there.
        for(j=i+1; j<n; j++)
        {
            if(arr[i]<=arr[j])
            {
                break;
            }
        }
        if(j==n)
        {
            std::cout << arr[i] << " ";
        }
    }
} 

//this method requires thetha(n)
void Array::leader2(int arr[], int n)
{
    int leaderHead = arr[n-1];
    std::cout << arr[n-1] << " ";
    for(int i = n-2; i>0; i--)
    {
        if(arr[i]>leaderHead)
        {
            std::cout << arr[i] << " ";
            leaderHead = arr[i];
        }
    }
}

int main()
{
    int arr[] = {10, 19, 45, 20, 23, 78};
    int testcase[] = {2,11, 3, 10, 4, 5, 5, 3, 6};
    int testcase2[] = {2,11, 3, 10, 4, 5, 5, 3, 6};

    Array arrObj;
    std::cout << "Checking of larget Element in arr " << arrObj.largestEle(arr, (sizeof(arr) / sizeof(arr[0]))) << std::endl;
    // std::cout << "Checking of larget Element in arr without n" << arrObj.largestElement(arr) << std::endl; //not give desired result
    std::cout << "SecondLargetIndex " << arrObj.secondLargestIndex(testcase, (sizeof(testcase) / sizeof(testcase[0]))) << std::endl;
    std::cout << "isSorted " << arrObj.isSorted(testcase, (sizeof(testcase) / sizeof(testcase[0]))) << std::endl;
    arrObj.leftRotateDplace(testcase,sizeof(testcase) / sizeof(testcase[0]),3);
    for(int i=0; i<sizeof(testcase) / sizeof(testcase[0]); i++)
    {
        std::cout << testcase[i] << " ";
    }
    std::cout << std::endl;
    arrObj.leader2(testcase2,sizeof(testcase2) / sizeof(testcase2[0]));
}