#include<iostream>
#include<vector>
using namespace std;

void combinationSum1(int* candidates, int target, int n, vector<vector<int>> &ans, vector<int> &temp, int sum, int idx){
    if(sum == target){
        ans.push_back(temp);
        return;
    }

    // If the sum exceeds the target or if we have exhausted the array
    if (sum > target || idx >= n) {
        return;
    }
    
    int curr = candidates[idx];
    if(curr <= target){
        temp.push_back(curr);
    }
    combinationSum1(candidates, target, n, ans, temp, sum+curr, idx);
    temp.pop_back();
    combinationSum1(candidates, target, n, ans, temp, sum, idx+1);
}

int main(){
    int target = 7;
    int size = 4;
    int candidates[size] = {2, 3, 6, 7};
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    int index = 0;

    combinationSum1(candidates, target, size, ans, temp, sum, index);

    for(auto x : ans){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }

}


// Time Complexity: O(2^N) [Exponential time complexity] 
// Space Complexity: O(N) [Output space] + O(N) [Recursive stack space] = O(N)