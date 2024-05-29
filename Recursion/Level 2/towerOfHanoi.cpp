#include<iostream>
using namespace std;

void towerOfHanoi(int n, string src, string helper, string dest){

    // if only 1 disk, simply move it from source to destination and return.
    if(n == 1){
        cout << "move disk 1 from " << src << " to " << dest << endl;
        return;
    }

    // move n-1 disks above the biggest disk to helper using destination as helper
    towerOfHanoi(n-1, src, dest, helper);
    // now the configuration is that helper has n-1 disks arranged, source has 1 disk and dest is empty

    // moving the biggest disk (bottom-most) from source to destination.
    cout << "move disk " << n << " from " << src << " to " << dest << endl;

    // moving those n-1 disks from helper to destination using source as helper (as it is free now) to attain the required configuration
    towerOfHanoi(n-1, helper, src, dest);

}

int main(){
    int n = 4;
    cout << "Steps to solve TOH : " << endl;
    towerOfHanoi(n, "A", "B", "C");
}