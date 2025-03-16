#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a string to read input from the standard input stream
    string arr;
    getline(cin, arr); // Read the first line of input
    
    // Get the length of the string
    int N = arr.length();
    
    // Read the number of queries K
    int K;
    cin >> K;
    cin.ignore(); // Ignore the newline character after the integer input
    
    // Initialize the result counter
    int res = 0;
    
    // Loop through each query
    for (int k = 0; k < K; k++) {
        // Read the input string for the current query
        string input;
        getline(cin, input);
        
        // Initialize counters for characters in the input string
        int a = 0;
        int b = 0;
        
        // Iterate through the character array
        for (int i = 0; i < N; i++) {
            // Count occurrences of the first character of the input string
            if (arr[i] == input[0]) 
                a++;
            // Count occurrences of the second character of the input string
            else if (arr[i] == input[1]) 
                b++;
            // If neither character is found, update the result and reset counters
            else {
                res += min(a, b);
                a = b = 0;
            }
        }
        // Add the minimum count of the two characters to the result
        res += min(a, b);
    }
    
    // Output the final result
    cout << res << endl;
    
    return 0;
}

// <END-OF-CODE>
