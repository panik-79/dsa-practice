#include<iostream>
using namespace std;

void reverseArray(int* arr, int size, int idx){

    // if index reaches more than half => we have swapped half arr with other half so no more swaps needed
    // therefore, return
    if(idx > size/2){
        return;
    }

    swap(arr[idx], arr[size - idx - 1]);
    reverseArray(arr, size, idx+1);

}

int main(){
    int n;
    n = 6;
    int arr[n] = {10, 20, 30, 40, 50, 60};
    reverseArray(arr, n, 0);
    for(int x : arr){
        cout << x << " ";
    }
}