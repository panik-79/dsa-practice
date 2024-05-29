#include<iostream>
using namespace std;

bool checkSorted(int* arr, int size, int idx) {
    // Base case: if the current index is the last index, array is sorted
    if(idx == size-1) return true;

    // Check if the next element is greater than or equal to the current element
    if(arr[idx+1] >= arr[idx]){
        // Recursive call for the next index
        return checkSorted(arr, size, idx+1);
    }
    else {
        // If next element is smaller, array is not sorted
        return false;
    }
}

int main(){
    int n = 5;
    int arr[n] = {10, 20, 30, 40, 50};
    bool isSorted = checkSorted(arr, n, 0);

    if(isSorted) cout << "Sorted";
    else cout << "Not Sorted";
}