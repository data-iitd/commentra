#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

// Defining the function calculate that takes two parameters, n and s
void calculate(int n, const string& s) {
    // Calculating the counts of 'R', 'G', and 'B'
    int rNum = count(s.begin(), s.end(), 'R');
    int gNum = count(s.begin(), s.end(), 'G');
    int bNum = count(s.begin(), s.end(), 'B');
    
    // Initializing sum to 0
    int sum = 0;
    
    // Iterating over possible step sizes from 1 to ceil(n / 2)
    for (int step = 1; step <= ceil(n / 2.0); ++step) {
        // Iterating over possible starting indices for the substring
        for (int i = 0; i <= n - 2 * step; ++i) {
            // Forming a substring of length 3
            string sub = {s[i], s[i + step], s[i + 2 * step]};
            
            // Checking if the substring matches any of the patterns
            if (sub == "RGB" || sub == "RBG" || sub == "BGR" || 
                sub == "BRG" || sub == "GBR" || sub == "GRB") {
                sum++;
            }
        }
    }
    
    // Printing the product of the counts of 'R', 'G', and 'B' minus sum
    cout << rNum * gNum * bNum - sum << endl;
}

int main() {
    // Taking input for N and S
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Calling the function calculate with N and S as arguments
    calculate(N, S);

    return 0;
}

// <END-OF-CODE>
