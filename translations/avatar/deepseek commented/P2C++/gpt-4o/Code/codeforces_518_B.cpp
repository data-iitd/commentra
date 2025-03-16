#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s, t;  // Taking two input strings
    std::cin >> s >> t;

    std::unordered_map<char, int> freqs;  // Map to store frequency of characters in s
    std::unordered_map<char, int> freqt;  // Map to store frequency of characters in t
    int yay = 0, whoops = 0;  // Initializing counters for yay and whoops

    // Populating the frequency maps
    for (char letra : s) {
        freqs[letra]++;  // Incrementing the count for character
    }

    for (char letra : t) {
        freqt[letra]++;  // Incrementing the count for character
    }

    // Counting yay by matching characters in freqs and freqt
    for (auto& pair : freqs) {
        char letra = pair.first;
        while (freqs[letra] > 0 && freqt.count(letra) > 0 && freqt[letra] > 0) {
            yay++;  // Incrementing yay if characters match
            freqs[letra]--;  // Decrementing the count in freqs
            freqt[letra]--;  // Decrementing the count in freqt
        }
    }

    // Counting whoops by transforming characters to match
    for (auto& pair : freqs) {
        char letra = pair.first;
        while (freqs[letra] > 0) {
            if (islower(letra) && freqt.count(toupper(letra)) > 0 && freqt[toupper(letra)] > 0) {
                whoops++;  // Incrementing whoops if transformation is possible
                freqs[letra]--;  // Decrementing the count in freqs
                freqt[toupper(letra)]--;  // Decrementing the count in freqt
            } else if (isupper(letra) && freqt.count(tolower(letra)) > 0 && freqt[tolower(letra)] > 0) {
                whoops++;  // Incrementing whoops if transformation is possible
                freqs[letra]--;  // Decrementing the count in freqs
                freqt[tolower(letra)]--;  // Decrementing the count in freqt
            } else {
                break;  // Breaking the loop if no more transformations are possible
            }
        }
    }

    std::cout << yay << " " << whoops << std::endl;  // Printing the final counts of yay and whoops

    return 0;
}  // <END-OF-CODE>
