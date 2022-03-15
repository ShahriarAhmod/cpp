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
