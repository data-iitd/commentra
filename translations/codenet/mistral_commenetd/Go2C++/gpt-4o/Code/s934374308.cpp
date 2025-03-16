#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Initialize variables
    int N, K, R, S, P;
    string T;

    // Read input from standard input
    cin >> N >> K >> R >> S >> P;
    cin >> T;

    // Initialize dictionary to store the count of each character
    unordered_map<char, int> dict = {{'r', 0}, {'s', 0}, {'p', 0}};

    // Initialize boolean arrays to represent the state of each character
    vector<bool> s(N, true);
    vector<bool> r(N, true);
    vector<bool> p(N, true);

    // Iterate through each character in the input string
    for (int i = 0; i < T.length(); i++) {
        char charCurrent = T[i];

        // Check if we have reached the window size
        if (i >= K) {
            // If the current character is the same as the character K positions back
            if (charCurrent == T[i - K]) {
                switch (charCurrent) {
                    case 's':
                        s[i % K] = !s[i % K];
                        continue;
                    case 'r':
                        r[i % K] = !r[i % K];
                        continue;
                    case 'p':
                        p[i % K] = !p[i % K];
                        continue;
                }
            } else {
                // If the current character is not the same, set the state of the character at index i%K to 'on'
                switch (charCurrent) {
                    case 's':
                        s[i % K] = true;
                        break;
                    case 'r':
                        r[i % K] = true;
                        break;
                    case 'p':
                        p[i % K] = true;
                        break;
                }
            }
        }

        // Update the dictionary with the count of the current character
        dict[charCurrent]++;
    }

    // Calculate and print the result
    int res = P * dict['r'] + S * dict['p'] + R * dict['s'];
    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
