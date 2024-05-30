#include<iostream>
#include<vector>
using namespace std;

// Recursive function to generate all possible letter combinations
void solve(string digits, string* mappings, string output, vector<string> &ans, int index) {
    // Base case: if we have processed all digits, add the output to the answer vector
    if(index == digits.length()) {
        ans.push_back(output);
        return;
    }
    
    // Get the current digit
    int currDigit = digits[index] - '0';
    
    // Get the corresponding string of characters for the current digit
    string str = mappings[currDigit];
    
    // Iterate through each character in the string
    for(int i = 0 ; i < str.length() ; i++) {
        // Append the current character to the output and make a recursive call for the next digit
        // The output will be updated in each recursive call and will be passed to the next call as well
        solve(digits, mappings, output+str[i], ans, index+1);
    }
}

// Function to generate all possible letter combinations for a given string of digits
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    
    // If the input string is empty, return an empty vector
    if(digits.length() == 0) return ans;
    
    string output = "";
    int index = 0;
    
    // Mapping of digits to corresponding strings of characters
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    // Call the recursive function to generate all possible combinations
    solve(digits, mapping, output, ans, index);
    
    return ans;
}

int main() {
    string digits = "23";
    
    // Generate all possible letter combinations for the given digits
    vector<string> v = letterCombinations(digits);
    
    // Print the generated combinations
    for(auto x : v) cout << x << " ";
    
    return 0;
}

// Time Complexity: O(4^N) [Exponential time complexity] because for each digit, we have 4 possible characters at max (for digits 7, 9) and 3 possible characters for the rest of the digits (2, 3, 4, 5, 6, 8) 

// Space Complexity: O(4^N) [Output space] + O(N) [Recursive stack space] = O(4^N) because the output space will contain 4^N strings in the worst case and the recursive stack space will be O(N) where N is the length of the input string.