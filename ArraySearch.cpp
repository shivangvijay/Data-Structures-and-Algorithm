#include <iostream>

class ArraySearch
{
public:
    /**
     * @brief 
     * 
     * @param arr 
     * @param n 
     * @param x 
     * @return int 
     */
    int itrSerach(int arr[], int n, int x);

    /**
     * @brief 
     * 
     */
    int BinarySearch(int arr[], int n, int x);

};

int ArraySearch::itrSerach(int arr[], int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }
    return -1;
}

// array is sorted
int ArraySearch::BinarySearch(int arr[], int n, int x)
{
    int lowIndex = 0;
    int highIndex = n-1;
    while(highIndex>=lowIndex)
    {
        int mid = (lowIndex+highIndex)/2;
        if(arr[mid] == x)
        {
            return mid;
        }
        else if(arr[mid] > x)
        {
            highIndex = mid-1;
        }
        else if(arr[mid] < x)
        {
            lowIndex = mid+1;
        }
    }
    return -1;
}


int main(){
    int arr[] = {2,3,4,5,66,89,101};
    ArraySearch arraySearch;
    std::cout << arraySearch.itrSerach(arr,5,66) << std::endl;
    std::cout << arraySearch.BinarySearch(arr,5,89) << std::endl;

}