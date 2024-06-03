#include<iostream>
using namespace std;

int lowerBound(int* arr, int n, int key){

    int low = 0, high = n-1, mid;
    int ans = -1;

    while(low <= high){
        mid = low + (high - low)/2;

        if(arr[mid] >= key){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int upperBound(int* arr, int n, int key){

    int low = 0, high = n-1, mid;
    int ans = -1;

    while(low <= high){
        mid = low + (high - low)/2;

        if(arr[mid] <= key){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}

int main(){
    int n = 10;
    int arr[10] = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    int x = 1;

    cout << lowerBound(arr, n, x) << endl;
    cout << upperBound(arr, n, x) << endl;
}