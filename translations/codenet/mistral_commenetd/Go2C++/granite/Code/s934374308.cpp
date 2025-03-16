
#include <iostream>
#include <map>
#include <string>

int main() {
    // Initialize variables
    int N, K, R, S, P;
    std::string T;

    // Read input from standard input
    std::cin >> N >> K >> R >> S >> P;
    std::cin >> T;

    // Initialize dictionary to store the count of each character
    std::map<char, int> dict = { {'r', 0}, {'s', 0}, {'p', 0} };

    // Initialize boolean arrays to represent the state of each character
    std::string char;
    bool s[N], r[N], p[N];

    // Initialize all characters to be in the 'on' state
    for (int i = 0; i < N; i++) {
        s[i] = true;
    }

    // Iterate through each character in the input string
    for (int i = 0; i < T.length(); i++) {
        // Assign the current character to a variable
        char = T.substr(i, 1);

        // Check if we have reached the window size
        if (i >= K) {
            // If the current character is a substring of the previous K characters, toggle the state of the character
            if (char == T.substr(i - K, K)) {
                switch (char[0]) {
                    case's':
                        // Toggle the state of the character at index i%K
                        if (s[i % K]) {
                            s[i % K] = false;
                            continue;
                        } else {
                            s[i % K] = true;
                        }
                        break;
                    case 'r':
                        // Toggle the state of the character at index i%K
                        if (r[i % K]) {
                            r[i % K] = false;
                            continue;
                        } else {
                            r[i % K] = true;
                        }
                        break;
                    case 'p':
                        // Toggle the state of the character at index i%K
                        if (p[i % K]) {
                            p[i % K] = false;
                            continue;
                        } else {
                            p[i % K] = true;
                        }
                        break;
                }

            // If the current character is not a substring of the previous K characters, update the state of the characters accordingly
            } else {
                switch (char[0]) {
                    case's':
                        // Set the state of the character at index i%K to 'on'
                        s[i % K] = true;
                        break;
                    case 'r':
                        // Set the state of the character at index i%K to 'on'
                        r[i % K] = true;
                        break;
                    case 'p':
                        // Set the state of the character at index i%K to 'on'
                        p[i % K] = true;
                        break;
                }

            }
        }

        // Update the dictionary with the count of the current character
        switch (char[0]) {
            case's':
                dict['s'] = dict['s'] + 1;
                break;
            case 'r':
                dict['r'] = dict['r'] + 1;
                break;
            case 'p':
                dict['p'] = dict['p'] + 1;
                break;
        }
    }

    // Calculate and print the result
    int res = P * dict['r'] + S * dict['p'] + R * dict['s'];
    std::cout << res << std::endl;

    // END-OF-CODE
}