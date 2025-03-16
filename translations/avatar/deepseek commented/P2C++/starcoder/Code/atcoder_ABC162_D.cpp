#include <bits/stdc++.h>

using namespace std;

// Function to calculate the number of possible ways to color a given string
void calculate(int n, string s) {
    // Converting the string s into a list of characters
    vector<char> arr(s.begin(), s.end());
    
    // Calculating the counts of 'R', 'G', and 'B'
    int rNum = 0, gNum = 0, bNum = 0;
    for (char c : arr) {
        if (c == 'R') {
            rNum++;
        } else if (c == 'G') {
            gNum++;
        } else if (c == 'B') {
            bNum++;
        }
    }
    
    // Initializing sum to 0
    int sum = 0;
    
    // Iterating over possible step sizes from 1 to ceil(n / 2) + 1
    for (int step = 1; step <= ceil(n / 2.0) + 1; step++) {
        // Iterating over possible starting indices for the substring
        for (int i = 0; i < n - 2 * step; i++) {
            // Forming a substring of length 3
            string s = "";
            s += arr[i];
            s += arr[i + step];
            s += arr[i + step * 2];
            
            // Checking if the substring matches any of the patterns
            if (s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB") {
                sum++;
            }
        }
    }
    
    // Printing the product of the counts of 'R', 'G', and 'B' minus sum
    cout << rNum * gNum * bNum - sum << endl;
}

// Driver Code
int main() {
    // Taking input for N and S
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Calling the function calculate with N and S as arguments
    calculate(n, s);
    
    return 0;
}

