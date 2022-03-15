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
    bubble(arr, s);
    cout<<"The smallest number: "<<arr[0]<<endl;
    cout<<"The largest number: "<<arr[s-1]<<endl;
}
