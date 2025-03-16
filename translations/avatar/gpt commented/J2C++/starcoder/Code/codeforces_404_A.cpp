#include <bits/stdc++.h>
using namespace std;

int main() {
    // Reading the size of the matrix (n x n)
    int n;
    cin >> n;
    
    // Initializing a 2D character array to store the matrix
    char arr[n][n];
    
    // Initializing a String array to store the input strings
    string str[n];
    
    // Reading n strings from the input
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    
    // Filling the 2D character array with characters from the input strings
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = str[i][j];
        }
    }
    
    // Storing the first two characters of the matrix for comparison
    char a = arr[0][0];
    char b = arr[0][1];
    
    // Checking if the first two characters are the same
    if (a == b) {
        cout << "NO" << endl; // If they are the same, print "NO"
    } else {
        // Initializing a boolean variable to track the result
        bool res = true;
        
        // Checking the conditions for the characters in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Checking if the current position is on the main diagonal or the anti-diagonal
                if (i == j || i + j == n - 1) {
                    // If it is, check if the character matches 'a'
                    if (arr[i][j]!= a) {
                        res = false; // If not, set result to false and break
                        break;
                    }
                } else {
                    // If it is not on the diagonals, check if the character matches 'b'
                    if (arr[i][j]!= b) {
                        res = false; // If not, set result to false and break
                        break;
                    }
                }
            }
        }
        
        // Print "YES" if the conditions are satisfied, otherwise print "NO"
        if (res) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

