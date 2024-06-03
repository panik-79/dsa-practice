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

int countOccurences(int first, int last){
    if (first == -1 && last == -1){
        return 0;
    }
    if(first == last){
        return 1;
    }
    else return last - first + 1;
}

int main() {
    int n = 15;
    int arr[n] = {10, 10, 10, 10, 20, 30, 30, 30, 40, 50, 50, 60, 80, 90, 90};
    int key = 20;

    int first =  firstOcc(arr, n, key);
    int last =  lastOcc(arr, n, key);

    int occurences = countOccurences(first, last);

    cout << occurences << endl;

    return 0;
}
