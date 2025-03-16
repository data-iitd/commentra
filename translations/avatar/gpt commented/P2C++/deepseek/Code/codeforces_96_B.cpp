#include <iostream>
#include <vector>
#include <algorithm>

// Initialize a vector to store valid numbers
std::vector<long long> l;
// Set a limit for the generated numbers
long long limit = 10000000000;

// Recursive function to generate numbers composed of 4s and 7s
void gen(long long number, int four, int seven) {
    // Base case: if the generated number exceeds the limit, stop recursion
    if (number > limit) {
        return;
    }
    // If the number is positive and the count of 4s equals the count of 7s, add it to the vector
    if (number > 0 && four == seven) {
        l.push_back(number);
    }
    // Recursively generate the next number by adding a 4
    gen(number * 10 + 4, four + 1, seven);
    // Recursively generate the next number by adding a 7
    gen(number * 10 + 7, four, seven + 1);
}

// Main function to execute the number generation and find the answer
int main() {
    // Start the generation process with initial values
    gen(0, 0, 0);
    // Sort the vector of generated numbers
    std::sort(l.begin(), l.end());
    // Read an integer input from the user
    long long n;
    std::cin >> n;
    long long ans = 0;
    // Iterate through the sorted vector to find the smallest number greater than or equal to n
    for (long long val : l) {
        if (val >= n) {
            ans = val;
            break;
        }
    }
    // Print the result
    std::cout << ans << std::endl;
    return 0;
}

