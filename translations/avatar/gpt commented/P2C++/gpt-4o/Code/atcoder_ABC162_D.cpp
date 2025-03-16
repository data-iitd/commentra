#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

void calculate(int n, const string& s) {
    // Count the occurrences of each color in the string
    int rNum = 0, gNum = 0, bNum = 0;
    
    for (char c : s) {
        if (c == 'R') rNum++;
        else if (c == 'G') gNum++;
        else if (c == 'B') bNum++;
    }
    
    // Initialize a variable to keep track of the number of valid RGB combinations found
    int sum = 0;
    
    // Set of valid RGB permutations
    unordered_set<string> validCombinations = {"RGB", "RBG", "BGR", "BRG", "GBR", "GRB"};
    
    // Loop through possible steps to form combinations of three characters
    for (int step = 1; step <= ceil(n / 2.0); step++) {
        // Loop through the string to form combinations based on the current step
        for (int i = 0; i <= n - 2 * step; i++) {
            // Create a substring of three characters at the current indices
            string combination = {s[i], s[i + step], s[i + step * 2]};
            
            // Check if the formed substring is one of the valid RGB permutations
            if (validCombinations.find(combination) != validCombinations.end()) {
                // Increment the count of valid combinations found
                sum++;
            }
        }
    }
    
    // Calculate and print the result: total combinations minus the valid RGB combinations found
    cout << rNum * gNum * bNum - sum << endl;
}

int main() {
    // Read the integer input N which represents the length of the string
    int N;
    cin >> N;

    // Read the string input S which consists of characters 'R', 'G', and 'B'
    string S;
    cin >> S;

    // Call the calculate function with the inputs N and S
    calculate(N, S);

    return 0;
}

// <END-OF-CODE>
