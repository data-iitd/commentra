
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    string S;
    
    // Read the integer input N which represents the length of the string
    cin >> N;
    
    // Read the string input S which consists of characters 'R', 'G', and 'B'
    cin >> S;
    
    int rNum = 0, gNum = 0, bNum = 0;
    int sum = 0;
    
    // Count the occurrences of each color in the string
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            rNum++;
        } else if (S[i] == 'G') {
            gNum++;
        } else if (S[i] == 'B') {
            bNum++;
        }
    }
    
    // Loop through possible steps to form combinations of three characters
    for (int step = 1; step <= (N + 2) / 2; step++) {
        for (int i = 0; i < N - 2 * step; i++) {
            // Create a substring of three characters at the current indices
            string s = S.substr(i, 3);
            
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
