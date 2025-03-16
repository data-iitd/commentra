#include <iostream>
#include <string>

int main() {
    // Declare variables to hold the number of operations (n) and the sequence of operations (s)
    int n;
    std::string s;
    
    // Read input values for n and s from the standard input
    std::cin >> n >> s;

    // Initialize variables to track the maximum count and the current count
    int max = 0;
    int cnt = 0;
    
    // Iterate over each character in the string s
    for (char r : s) {
        // Increment count for 'I' and decrement for any other character
        if (r == 'I') {
            cnt++;
        } else {
            cnt--;
        }

        // Update max if the current count exceeds the previously recorded maximum
        if (cnt > max) {
            max = cnt
        }
    }

    // Print the maximum count achieved during the iterations
    std::cout << max << std::endl;
}

