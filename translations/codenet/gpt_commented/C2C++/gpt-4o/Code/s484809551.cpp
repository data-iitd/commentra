#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// Define constants for maximum sizes
const size_t N_MAX = 100;
const size_t P_MAX = 100;

// Function to find the last occurrence of a substring within a string
static const char* strrstr(const char* string, const char* pattern) {
    size_t offset = 0;
    const char* lastP = nullptr;

    const char* searchResult = nullptr;
    // Loop to find the last occurrence of the pattern
    while ((searchResult = strstr(&(string[offset]), pattern)) != nullptr && string[offset] != '\0') {
        lastP = searchResult; // Update last found position
        offset++; // Move offset to search for further occurrences
    }

    return lastP; // Return the last found position
}

// Main function to execute the program
int main() {
    const char patternBase[] = "keyence"; // Define the pattern to search for
    char top[8], bottom[8]; // Buffers to hold split parts of the pattern
    char S[101]; // Buffer to hold the input string

    // Read the input string
    cin >> S;

    const size_t len = strlen(S); // Get the length of the input string
    bool found = false; // Flag to indicate if the pattern is found

    // Loop through each possible split point in the pattern
    for (size_t offset = 0; offset < strlen(patternBase); offset++) {
        // Split the pattern into top and bottom parts
        strncpy(top, patternBase, offset);
        top[offset] = '\0'; // Null-terminate the top part
        strncpy(bottom, &(patternBase[offset]), strlen(patternBase) - offset);
        bottom[strlen(patternBase) - offset] = '\0'; // Null-terminate the bottom part

        // Search for the top part in the input string
        const char* topSearch = strstr(S, top);
        if (topSearch != nullptr) {
            // Search for the bottom part after the found top part
            const char* bottomSearch = strrstr(&(topSearch[offset]), bottom);
            if (bottomSearch != nullptr) {
                size_t sepCount = 0; // Counter for separators

                // Count the number of separators between top and bottom parts
                if (topSearch != S) {
                    sepCount++; // Increment if there's text before the top part
                }
                if (&(topSearch[offset]) != bottomSearch) {
                    sepCount++; // Increment if there's text between top and bottom parts
                }
                if (bottomSearch[strlen(bottom)] != '\0') {
                    sepCount++; // Increment if there's text after the bottom part
                }

                // Check if the number of separators is less than or equal to 1
                if (sepCount <= 1) {
                    found = true; // Set found flag to true
                    break; // Exit the loop as the pattern is found
                }
            }
        }
    }

    // Output the result based on whether the pattern was found
    cout << (found ? "YES" : "NO") << endl;

    return 0; // Return success
}

// <END-OF-CODE>
