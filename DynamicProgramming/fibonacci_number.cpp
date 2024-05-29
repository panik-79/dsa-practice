#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

long long int fibUsingRecursion(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibUsingRecursion(n - 1) + fibUsingRecursion(n - 2);
}


// Memoization: Top-down approach
// We store the results of subproblems in a table (generally implemented using an array)
// The table is initialized with a special value (usually -1) to indicate that the result of that subproblem has not been computed yet
// Whenever we need the result of a subproblem, we first check whether it has already been computed
// If it has been computed, we return the stored value, otherwise, we compute the value and store it in the table
// This way, we avoid redundant computations
// Time complexity: O(n)
// Space complexity: O(n)
long long int fibUsingMemoization(vector<long long int> &dp, int n) {
    if (n == 0 || n == 1) {
        return dp[n] = n;
    }
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibUsingMemoization(dp, n - 1) + fibUsingMemoization(dp, n - 2);
}

// Tabulation: Bottom-up approach
// We build the solution of the problem by solving the subproblems in a bottom-up manner
// We start with the base case and build up the solution for larger subproblems
// We store the results of subproblems in a table (generally implemented using an array)
// Time complexity: O(n)
// Space complexity: O(n)
long long int fibUsingTabulation(int n) {
    vector<long long int> dp(n + 1, -1);
    dp[0] = 0; // Base case
    dp[1] = 1; // Base case

    // Fill up the remaining dp table using recurrence relation and building up the solution from the base case
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space optimized version of tabulation method -> O(1) space
// We only need the last two values to compute the next value
// Therefore, no need to store all the values in the dp table
long long int fibUsingTabulationOptimized(int n) {
    if (n == 0 || n == 1) return n;

    long long int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n = 50; // Compute the 50th Fibonacci number

    clock_t start = clock();
    cout << "Fib(" << n << ") using recursion: ";
    try {
        cout << fibUsingRecursion(n) << endl;
    } catch (...) {
        cout << "Recursion limit exceeded or too long computation time." << endl;
    }
    cout << "Time taken (recursion): " << (float)(clock() - start) / CLOCKS_PER_SEC << " secs" << endl;

    start = clock();
    vector<long long int> dp(n + 1, -1);
    cout << "Fib(" << n << ") using memoization: " << fibUsingMemoization(dp, n) << endl;
    cout << "Time taken (memoization): " << (float)(clock() - start) / CLOCKS_PER_SEC << " secs" << endl;

    start = clock();
    cout << "Fib(" << n << ") using tabulation: " << fibUsingTabulation(n) << endl;
    cout << "Time taken (tabulation): " << (float)(clock() - start) / CLOCKS_PER_SEC << " secs" << endl;

    start = clock();
    cout << "Fib(" << n << ") using optimized tabulation: " << fibUsingTabulationOptimized(n) << endl;
    cout << "Time taken (optimized tabulation): " << (float)(clock() - start) / CLOCKS_PER_SEC << " secs" << endl;


    return 0;
}


// output

// Fib(50) using recursion: 12586269025
// Time taken (recursion): 143.318 secs
// Fib(50) using memoization: 12586269025
// Time taken (memoization): 0.001 secs
// Fib(50) using tabulation: 12586269025
// Time taken (tabulation): 0 secs
// Fib(50) using optimized tabulation: 12586269025
// Time taken (optimized tabulation): 0 secs