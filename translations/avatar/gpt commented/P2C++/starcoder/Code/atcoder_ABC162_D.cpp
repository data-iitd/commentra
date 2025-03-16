#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the integer input N which represents the length of the string
    int N;
    cin >> N;
    
    // Read the string input S which consists of characters 'R', 'G', and 'B'
    string S;
    cin >> S;
    
    // Convert the string into a list of characters for easier manipulation
    vector<char> arr(S.begin(), S.end());
    
    // Count the occurrences of each color in the string
    int rNum = count(arr.begin(), arr.end(), 'R');
    int gNum = count(arr.begin(), arr.end(), 'G');
    int bNum = count(arr.begin(), arr.end(), 'B');
    
    // Initialize a variable to keep track of the number of valid RGB combinations found
    int sum = 0;
    
    // Loop through possible steps to form combinations of three characters
    for (int step = 1; step <= ceil(N / 2.0); step++) {
        // Loop through the string to form combinations based on the current step
        for (int i = 0; i < N - 2 * step; i++) {
            // Create a substring of three characters at the current indices
            string s = string(arr.begin() + i, arr.begin() + i + step) + string(arr.begin() + i + step, arr.begin() + i + step * 2);
            
            // Check if the formed substring is one of the valid RGB permutations
            if (s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB") {
                // Increment the count of valid combinations found
                sum++;
            }
        }
    }
    
    // Calculate and print the result: total combinations minus the valid RGB combinations found
    cout << rNum * gNum * bNum - sum << endl;
    
    return 0;
}

