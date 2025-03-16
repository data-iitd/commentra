
#include <iostream>
using namespace std;

// Define aliases for common data types
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

// Include necessary libraries
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>

// Function to solve the problem
void solve(){
    // Initialize variables
    int a, b;

    // Read input values from the user
    cin >> a >> b;

    // Initialize output string
    string ans;

    // Determine the answer based on the input values
    if (a == 1 && b == 1){
        // Both a and b are equal to 1, so the answer is a draw
        ans = "Draw";
    } else if (a == 1){
        // a is equal to 1, so the answer is Alice
        ans = "Alice";
    } else {
        // Neither a nor b is equal to 1, so the answer is Bob
        ans = "Bob";
    }

    // Print the answer to the console
    cout << ans << endl;
}

int main(){
    // Call the solve function to solve the problem
    solve();

    return 0;
}

