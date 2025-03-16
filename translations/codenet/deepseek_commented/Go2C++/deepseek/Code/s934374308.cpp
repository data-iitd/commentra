#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int N, K, R, S, P;
    std::string T;
    std::cin >> N >> K >> R >> S >> P;
    std::cin >> T;

    // Initialize the dictionary to keep track of the counts of 'r', 's', and 'p'
    std::unordered_map<char, int> dict = {{'r', 0}, {'s', 0}, {'p', 0}};
    // Initialize a string to store the current character
    char char_ = '\0';
    // Initialize a boolean array to keep track of the availability of each choice for each player
    bool* s = new bool[N]();
    // Initialize all elements of the array to true
    for (int i = 0; i < N; i++) {
        s[i] = true;
    }
    // Create copies of the array for 'r', 'p'
    bool* r = new bool[N]();
    bool* p = new bool[N]();
    std::copy(s, s + N, r);
    std::copy(s, s + N, p);

    // Iterate over each character in the string T
    for (int i = 0; i < T.length(); i++) {
        char_ = T[i];
        // Check if the current index is greater than or equal to K
        if (i >= K) {
            // Check if the last K characters are the same as the current character
            if (char_ == T[i - K]) {
                // Update the availability of the choice based on the current character
                if (char_ == 's') {
                    if (s[i % K]) {
                        s[i % K] = false;
                        continue;
                    } else {
                        s[i % K] = true;
                    }
                } else if (char_ == 'r') {
                    if (r[i % K]) {
                        r[i % K] = false;
                        continue;
                    } else {
                        r[i % K] = true;
                    }
                } else if (char_ == 'p') {
                    if (p[i % K]) {
                        p[i % K] = false;
                        continue;
                    } else {
                        p[i % K] = true;
                    }
                }
            } else {
                // Set the availability of the choice based on the current character
                if (char_ == 's') {
                    s[i % K] = true;
                } else if (char_ == 'r') {
                    r[i % K] = true;
                } else if (char_ == 'p') {
                    p[i % K] = true;
                }
            }
        }
        // Update the counts in the dictionary based on the current character
        dict[char_]++;
    }

    // Calculate the result by multiplying the counts of 'r', 's', and 'p' with their respective values (P, S, R)
    int res = P * dict['r'] + S * dict['p'] + R * dict['s'];
    // Print the result
    std::cout << res << std::endl;

    // Clean up dynamically allocated memory
    delete[] s;
    delete[] r;
    delete[] p;

    return 0;
}
