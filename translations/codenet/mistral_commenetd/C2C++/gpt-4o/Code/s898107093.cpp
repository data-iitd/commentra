#include <iostream>
#include <vector>
#include <string>

int main() {
    // Declare variables
    int n; // number of strings to be compared
    int taro = 0; // score for Taro
    int hanako = 0; // score for Hanako

    // Read the number of strings to be compared from the standard input
    std::cin >> n;

    // Use vectors to store strings for t and h
    std::vector<std::string> t(n);
    std::vector<std::string> h(n);

    // Initialize the loops for t and h arrays
    for (int i = 0; i < n; i++) {
        // Read strings from the standard input and store them in t and h arrays
        std::cin >> t[i];
        std::cin >> h[i];

        // Compare the strings and update the scores accordingly
        if (t[i] < h[i]) {
            hanako += 3; // Hanako gets 3 points if the current string in t is smaller than the corresponding string in h
        } else if (t[i] > h[i]) {
            taro += 3; // Taro gets 3 points if the current string in t is larger than the corresponding string in h
        } else { // If the strings are equal
            taro += 1; // Taro gets 1 point if the strings are equal
            hanako += 1; // Hanako gets 1 point if the strings are equal
        }
    }

    // Print the scores for Taro and Hanako
    std::cout << taro << " " << hanako << std::endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
