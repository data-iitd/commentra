#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Read two strings from input
    std::string s, t;
    std::getline(std::cin, s);
    std::getline(std::cin, t);

    // Initialize unordered maps to store frequency counts of characters in both strings
    std::unordered_map<char, int> freqs;
    std::unordered_map<char, int> freqt;

    // Initialize counters for matching characters
    int yay = 0, whoops = 0;

    // Count the frequency of each character in the first string 's'
    for (char letra : s) {
        freqs[letra]++;
    }

    // Count the frequency of each character in the second string 't'
    for (char letra : t) {
        freqt[letra]++;
    }

    // Compare character frequencies from both strings to count exact matches
    for (auto& pair : freqs) {
        char letra = pair.first;
        while (freqs[letra] > 0 && freqt.count(letra) > 0 && freqt[letra] > 0) {
            yay++;  // Increment the count of exact matches
            freqs[letra]--;  // Decrease the count in the first string
            freqt[letra]--;  // Decrease the count in the second string
        }
    }

    // Compare remaining characters for case-insensitive matches
    for (auto& pair : freqs) {
        char letra = pair.first;
        while (freqs[letra] > 0) {
            // Check for a lowercase letter in 's' and its uppercase counterpart in 't'
            if (std::islower(letra) && freqt.count(std::toupper(letra)) > 0 && freqt[std::toupper(letra)] > 0) {
                whoops++;  // Increment the count of case-insensitive matches
                freqs[letra]--;  // Decrease the count in the first string
                freqt[std::toupper(letra)]--;  // Decrease the count in the second string
            }
            // Check for an uppercase letter in 's' and its lowercase counterpart in 't'
            else if (std::isupper(letra) && freqt.count(std::tolower(letra)) > 0 && freqt[std::tolower(letra)] > 0) {
                whoops++;  // Increment the count of case-insensitive matches
                freqs[letra]--;  // Decrease the count in the first string
                freqt[std::tolower(letra)]--;  // Decrease the count in the second string
            } else {
                break;  // Exit the loop if no more matches can be found
            }
        }
    }

    // Print the results: number of exact matches and case-insensitive matches
    std::cout << yay << " " << whoops << std::endl;

    return 0;
}

// <END-OF-CODE>
