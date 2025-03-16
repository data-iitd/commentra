#include <iostream>
#include <string>
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
    unordered_map<char, int> dict;
    dict['r'] = 0;
    dict['s'] = 0;
    dict['p'] = 0;

    // Initialize boolean arrays to represent the state of each character
    bool s[N] = {false};
    bool r[N] = {false};
    bool p[N] = {false};

    // Iterate through each character in the input string
    for (int i = 0; i < T.length(); i++) {
        // Update the dictionary with the count of the current character
        dict[T[i]]++;

        // Check if we have reached the window size
        if (i >= K) {
            // If the current character is a substring of the previous K characters, toggle the state of the character
            if (T[i] == T[i - K]) {
                switch (T[i]) {
                    case 's':
                        // Toggle the state of the character at index i % K
                        s[i % K] = !s[i % K];
                        break;
                    case 'r':
                        // Toggle the state of the character at index i % K
                        r[i % K] = !r[i % K];
                        break;
                    case 'p':
                        // Toggle the state of the character at index i % K
                        p[i % K] = !p[i % K];
                        break;
                }
            }
        }
    }

    // Calculate and print the result
    int res = P * dict['r'] + S * dict['p'] + R * dict['s'];
    cout << res << endl;

    return 0;
}
