#include<bits/stdc++.h>
using namespace std;
int binSearch(int arr[], int l, int r, int find) {

    if(r >= l) {
        int mid = l + (r-1) / 2;

        if(arr[mid] == find) {
            return mid;
        }

        else if(arr[mid] > find) {
            return binSearch(arr, l, mid - 1, find);
        }

        else {
            return binSearch(arr, mid+1, r, find);
        }
    }

    return -1;

}

int main() {
    int arr[] = {1, 3, 4, 10, 32, 64};
    int n = sizeof(arr) / sizeof(arr[0]);


    int find = 4;


    int searchResult = binSearch(arr, 0, n-1, find);

    if( searchResult == -1) {
        cout<<"Number not found!"<<endl;
    }
    else {
        cout<<"Number found at "<<searchResult+1<<endl;
    }


}
