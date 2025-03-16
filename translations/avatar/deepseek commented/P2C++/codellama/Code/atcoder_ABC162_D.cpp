
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Defining the function calculate that takes two parameters, n and s
void calculate(int n, string s) {
    // Converting the string s into a list of characters
    char arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = s[i];
    }
    
    // Calculating the counts of 'R', 'G', and 'B'
    int rNum = 0, gNum = 0, bNum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'R') {
            rNum++;
        } else if (arr[i] == 'G') {
            gNum++;
        } else if (arr[i] == 'B') {
            bNum++;
        }
    }
    
    // Initializing sum to 0
    int sum = 0;
    
    // Iterating over possible step sizes from 1 to math.ceil(n / 2) + 1
    for (int step = 1; step <= ceil(n / 2) + 1; step++) {
        // Iterating over possible starting indices for the substring
        for (int i = 0; i < n - 2 * step; i++) {
            // Forming a substring of length 3
            string s = "";
            for (int j = i; j < i + 3; j++) {
                s += arr[j];
            }
            
            // Checking if the substring matches any of the patterns
            if (s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB") {
                sum = sum + 1;
            }
        }
    }
    
    // Printing the product of the counts of 'R', 'G', and 'B' minus sum
    cout << rNum * gNum * bNum - sum << endl;
}

// Calling the function calculate with N and S as arguments
int main() {
    int N;
    string S;
    cin >> N >> S;
    calculate(N, S);
    return 0;
}

