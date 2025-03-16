#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// solution function takes an integer n and a vector of integers a.
// It calculates the maximum frequency of any number or its two consecutive successors in the array.
int solution(int n, vector<int>& a) {
    // Create a memoization array to count occurrences of numbers and their successors.
    vector<int> memo(1e5 + 2, 0);
    
    // Iterate through each number in the input array.
    for (int num : a) {
        // Increment the count for the current number and its two successors.
        memo[num]++;
        memo[num + 1]++;
        memo[num + 2]++;
    }
    
    // Initialize the output variable to track the maximum frequency found.
    int out = 0;
    
    // Iterate through the memoization array to find the maximum frequency.
    for (int num : memo) {
        // Update the output if the current count is greater than the current maximum.
        if (num > 0) {
            out = max(out, num);
        }
    }
    
    // Return the maximum frequency found.
    return out;
}

int main() {
    // Declare a variable to hold the number of elements.
    int n;
    
    // Read the number of elements from standard input.
    cin >> n;
    
    // Create a vector to hold the input integers.
    vector<int> a(n);
    
    // Read each integer into the vector.
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Call the solution function and print the result.
    cout << solution(n, a) << endl;
    
    return 0;
}
