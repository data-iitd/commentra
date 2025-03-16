// Include necessary headers
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to read a string from standard input
string ReadString() {
    string s;
    cin >> s;
    return s;
}

int main() {
    // Initialize two empty strings S and T
    string S = ReadString();
    string T = ReadString();

    // Initialize max as 0
    int max = 0;

    // Loop through all possible substrings of S with length equal to T
    for (size_t i = 0; i <= S.length() - T.length(); i++) {
        // Initialize a counter c for the number of matching characters between S[i:i+len(T)] and T
        int c = 0;

        // Check character by character for matching characters
        for (size_t j = 0; j < T.length(); j++) {
            // If current characters match, increment counter c
            if (S[i + j] == T[j]) {
                c++;
            }
        }

        // If current substring has more matching characters than the current max, update max
        if (max < c) {
            max = c;
        }
    }

    // Print the length of the shortest substring of S that matches T with all characters
    cout << T.length() - max << endl;

    return 0;
}

// <END-OF-CODE>
