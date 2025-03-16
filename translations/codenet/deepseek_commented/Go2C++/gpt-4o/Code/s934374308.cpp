#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P;
    cin >> T;

    // Initialize the dictionary to keep track of the counts of 'r', 's', and 'p'
    unordered_map<char, int> dict = {{'r', 0}, {'s', 0}, {'p', 0}};
    // Initialize a boolean vector to keep track of the availability of each choice for each player
    vector<bool> s(N, true);
    // Create copies of the vector for 'r', 'p'
    vector<bool> r = s;
    vector<bool> p = s;

    // Iterate over each character in the string T
    for (int i = 0; i < T.length(); i++) {
        char charT = T[i];
        // Check if the current index is greater than or equal to K
        if (i >= K) {
            // Check if the last K characters are the same as the current character
            if (charT == T[i - K]) {
                // Update the availability of the choice based on the current character
                switch (charT) {
                    case 's':
                        if (s[i % K]) {
                            s[i % K] = false;
                            continue;
                        } else {
                            s[i % K] = true;
                        }
                        break;
                    case 'r':
                        if (r[i % K]) {
                            r[i % K] = false;
                            continue;
                        } else {
                            r[i % K] = true;
                        }
                        break;
                    case 'p':
                        if (p[i % K]) {
                            p[i % K] = false;
                            continue;
                        } else {
                            p[i % K] = true;
                        }
                        break;
                }
            } else {
                // Set the availability of the choice based on the current character
                switch (charT) {
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
        // Update the counts in the dictionary based on the current character
        dict[charT]++;
    }

    // Calculate the result by multiplying the counts of 'r', 's', and 'p' with their respective values (P, S, R)
    int res = P * dict['r'] + S * dict['p'] + R * dict['s'];
    // Print the result
    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
