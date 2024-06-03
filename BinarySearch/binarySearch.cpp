#include<iostream>
using namespace std;

// Recursive approach
int binarySearchRecursive(int* arr, int key, int start, int end){

    // calculate mid index of the array
    int mid = start + (end-start)/2;

    // if key is found at mid index, return mid 
    if(arr[mid] == key){
        return mid;
    }

    // if key is not found in the array
    if(start > end){
        return -1;
    }

    // if key is greater than mid element, search in right half of the array
    else if(arr[mid] < key){
        return binarySearchRecursive(arr, key, mid+1, end);
    }

    // if key is smaller than mid element, search in left half of the array
    else return binarySearchRecursive(arr, key, start, mid-1);

}


// Iterative approach
int binarySearchIterative(int* arr, int key, int start, int end){

    // loop until start index is less than or equal to end index
    while(start <= end){

        // calculate mid index of the array
        int mid = start + (end-start)/2;

        // if key is greater than mid element, search in right half of the array
        if(arr[mid] < key){
            start = mid + 1;
        }
        // if key is smaller than mid element, search in left half of the array
        else if(arr[mid] > key){
            end = mid - 1;
        }
        // if key is found at mid index, return mid
        else{
            return mid;
        }
        
    }
    // if key is not found in the array return -1
    return -1;
}

int main(){
    int n = 7;
    int arr[7] = {10, 20, 30, 40, 50, 60, 70};
    int key = 60;
    int start = 0;
    int end = n-1;
    cout << binarySearchRecursive(arr, key, start, end) << endl;
    cout << binarySearchIterative(arr, key, start, end) << endl;
}