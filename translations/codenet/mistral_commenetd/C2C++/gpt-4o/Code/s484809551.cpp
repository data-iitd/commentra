#include <iostream>
#include <cstring>
#include <string>

// Define constants
const size_t N_MAX = 100;
const size_t P_MAX = 100;

// Function to find the last occurrence of a substring in a string
static const char* strrstr(const char* string, const char* pattern) {
    size_t offset = 0;
    const char* lastP = nullptr;

    const char* searchResult = nullptr;
    while ((searchResult = strstr(&(string[offset]), pattern)) != nullptr && string[offset] != '\0') {
        lastP = searchResult;
        offset++;
    }

    return lastP;
}

int main() {
    // Define pattern base string
    const char patternBase[] = "keyence";
    char top[8], bottom[8];
    char S[101];

    // Read input string from standard input
    std::cin >> S;

    // Calculate length of input string
    const size_t len = strlen(S);
    bool found = false;

    // Loop through each character in pattern base string
    for (size_t offset = 0; offset < strlen(patternBase); offset++) {
        // Copy substring up to current character to top variable
        strncpy(top, patternBase, offset);
        top[offset] = '\0';

        // Copy substring from current character to end of pattern base string to bottom variable
        strncpy(bottom, &(patternBase[offset]), strlen(patternBase) - offset);
        bottom[strlen(patternBase) - offset] = '\0';

        // Search for top substring in input string
        const char* topSearch = strstr(S, top);

        // If top substring is found
        if (topSearch != nullptr) {
            // Search for bottom substring after top substring in input string
            const char* bottomSearch = strrstr(&(topSearch[offset]), bottom);

            // If bottom substring is found
            if (bottomSearch != nullptr) {
                // Calculate number of separators between top and bottom substrings
                size_t sepCount = 0;

                // If topSearch is not the first occurrence of top substring in input string
                if (topSearch != S) {
                    sepCount++;
                }

                // If topSearch is not the same as bottomSearch
                if (&(topSearch[offset]) != bottomSearch) {
                    sepCount++;
                }

                // If bottomSearch is not the last character in input string
                if (bottomSearch[strlen(bottom)] != '\0') {
                    sepCount++;
                }

                // If number of separators is less than or equal to 1
                if (sepCount <= 1) {
                    found = true;
                    break;
                }
            }
        }
    }

    // Print output based on whether pattern is found or not
    std::cout << (found ? "YES" : "NO") << std::endl;

    return 0;
}

// <END-OF-CODE>
