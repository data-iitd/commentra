#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// solution function takes an integer n and a vector of integers a.
// It calculates the maximum frequency of any number or its two consecutive successors in the array.
int solution(int n, vector<int> &a) {
        // Create a memoization array to count occurrences of numbers and their successors.
        int memo[100000 + 2] = {0};
        
        // Iterate through each number in the input array.
        for (int i = 0; i < n; i++) {
                // Increment the count for the current number and its two successors.
                memo[a[i]]++;
                memo[a[i] + 1]++;
                memo[a[i] + 2]++;
        }
        
        // Initialize the output variable to track the maximum frequency found.
        int out = 0;
        
        // Iterate through the memoization array to find the maximum frequency.
        for (int i = 0; i < 100000 + 2; i++) {
                // Update the output if the current count is greater than the current maximum.
                if (memo[i] > 0) {
                        out = max(out, memo[i]);
                }
        }
        
        // Return the maximum frequency found.
        return out;
}

// max function returns the greater of two integers x and y.
int max(int x, int y) {
        if (x > y) {
                return x;
        }
        return y;
}

// main function is the entry point of the program.
int main() {
        // Declare a variable to hold the number of elements.
        int n;
        
        // Read the number of elements from standard input.
        cin >> n;
        
        // Create a vector to hold the input integers.
        vector<int> a(n);
        
        // Read each integer into the vector.
        for (int i = 0; i < n; i++) {
                cin >> a[i];
        }
        
        // Call the solution function and print the result.
        cout << solution(n, a) << endl;
}

