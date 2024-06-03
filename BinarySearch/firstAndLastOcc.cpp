#include<iostream>
using namespace std;

int firstOcc(int* arr, int n, int key) {
    int firstOcc = -1;
    int start = 0;
    int end = n - 1;
    // Loop until start index is less than or equal to end index
    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            firstOcc = mid;
            end = mid - 1;  // Continue searching in the left half
        } else if (arr[mid] > key) {
            end = mid - 1;  // Move to the left half
        } else {
            start = mid + 1;  // Move to the right half
        }
    }
    return firstOcc;
}

int lastOcc(int* arr, int n, int key) {
    int lastOcc = -1;
    int start = 0;
    int end = n - 1;
    // Loop until start index is less than or equal to end index
    while (start <= end) {
        
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            lastOcc = mid;
            start = mid + 1;  // Continue searching in the right half
        } else if (arr[mid] > key) {
            end = mid - 1;  // Move to the left half
        } else {
            start = mid + 1;  // Move to the right half
        }
    }
    return lastOcc;
}

int main() {
    int n = 10;
    int arr[n] = {10, 20, 30, 30, 30, 40, 50, 60, 80, 90};
    int key = 30;

    cout << firstOcc(arr, n, key) << endl;
    cout << lastOcc(arr, n, key) << endl;

    return 0;
}
