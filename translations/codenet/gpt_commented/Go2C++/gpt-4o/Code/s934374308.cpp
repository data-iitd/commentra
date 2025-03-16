#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Declare variables for input values
    int N, K, R, S, P;
    string T;

    // Read input values: N (length of string), K (window size), R, S, P (points for each move)
    cin >> N >> K >> R >> S >> P;
    cin >> T;

    // Initialize a dictionary to count occurrences of each move
    unordered_map<string, int> dict = {{"r", 0}, {"s", 0}, {"p", 0}};
    string charMove;

    // Create vectors to track the state of each move within the last K moves
    vector<bool> s(N, true); // For 's'
    vector<bool> r(N, true); // For 'r'
    vector<bool> p(N, true); // For 'p'

    // Iterate through each character in the input string T
    for (int i = 0; i < T.length(); i++) {
        charMove = T.substr(i, 1); // Get the current character

        // Check if we are within the bounds of K
        if (i >= K) {
            // If the current character is the same as the character K positions back
            if (charMove == T.substr(i - K, 1)) {
                // Toggle the availability of the move based on the current character
                if (charMove == "s") {
                    if (s[i % K]) {
                        s[i % K] = false; // Mark 's' as used
                        continue;
                    } else {
                        s[i % K] = true; // Mark 's' as available again
                    }
                } else if (charMove == "r") {
                    if (r[i % K]) {
                        r[i % K] = false; // Mark 'r' as used
                        continue;
                    } else {
                        r[i % K] = true; // Mark 'r' as available again
                    }
                } else if (charMove == "p") {
                    if (p[i % K]) {
                        p[i % K] = false; // Mark 'p' as used
                        continue;
                    } else {
                        p[i % K] = true; // Mark 'p' as available again
                    }
                }
            } else {
                // If the current character is different from the character K positions back
                if (charMove == "s") {
                    s[i % K] = true; // Mark 's' as available
                } else if (charMove == "r") {
                    r[i % K] = true; // Mark 'r' as available
                } else if (charMove == "p") {
                    p[i % K] = true; // Mark 'p' as available
                }
            }
        }

        // Count the occurrences of each move
        dict[charMove]++; // Increment count for the current move
    }

    // Calculate the total score based on the counts and respective points
    int res = P * dict["r"] + S * dict["p"] + R * dict["s"];

    // Print the final result
    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
