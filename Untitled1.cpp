// C++ program to implement Linear Search using recursion
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
        return i;
    return -1;
}

int main()
{
    int arr[] = {1, 5, 7, 9, 11};
    int x = 1;
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = linearSearch(arr, n, x);
    (result == -1) ? cout<< "Element not found in the array" : cout<< "Element found at index : " << result;
    return 0;
}
