#include<bits/stdc++.h>
using namespace std;

void Swap(int *a, int *b) {
    int temp = *a;
        *a = *b;
        *b = temp;
}

void bubble(int arr[], int s) {

    for(int i = 0; i < s; i++) {

        for(int j = 0; j < s - i; j++) {

            if(arr[j] > arr[j+1]) {
                Swap(&arr[j], &arr[j+1]);
            }

        }

    }

}

// 2 1 3 4 5 6


int main() {
    int arr[] = {1, 5, 2, 9, 8, 3, 4, 6, 12, 10};
    int s = sizeof(arr) / sizeof(arr[0]);

    cout<<"The Unsorted Array: ";
    for(int k = 0; k < s; k++) {
        cout<<arr[k]<<" ";
    }
    cout<<endl;


    bubble(arr, s);

    cout<<"The Sorted Array: ";

    for(int j = 0; j < s; j++) {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}
