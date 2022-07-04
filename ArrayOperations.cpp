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

int main()
{
    int arr[] = {10,19,45,20,23,78};
    Array arrObj;
    std::cout << "Checking of larget Element in arr " << arrObj.largestEle(arr,(sizeof(arr)/sizeof(arr[0]))) << std::endl;
}