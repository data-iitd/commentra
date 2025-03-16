#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s, t;
    std::unordered_map<char, int> freqs;
    std::unordered_map<char, int> freqt;
    int yay = 0, whoops = 0;

    // Taking two input strings
    std::cin >> s >> t;

    // Populating the frequency dictionaries
    for (char letra : s) {
        if (freqs.find(letra) != freqs.end()) {
            freqs[letra]++;  // Incrementing the count if character is already in dictionary
        } else {
            freqs[letra] = 1;  // Initializing the count if character is not in dictionary
        }
    }

    for (char letra : t) {
        if (freqt.find(letra) != freqt.end()) {
            freqt[letra]++;  // Incrementing the count if character is already in dictionary
        } else {
            freqt[letra] = 1;  // Initializing the count if character is not in dictionary
        }
    }

    // Counting yay by matching characters in freqs and freqt
    for (auto& pair : freqs) {
        char letra = pair.first;
        while (pair.second > 0 && freqt.find(letra) != freqt.end() && freqt[letra] > 0) {
            yay++;  // Incrementing yay if characters match
            pair.second--;  // Decrementing the count in freqs
            freqt[letra]--;  // Decrementing the count in freqt
        }
    }

    // Counting whoops by transforming characters to match
    for (auto& pair : freqs) {
        char letra = pair.first;
        while (pair.second > 0) {
            if (islower(letra) && isupper(letra) && freqt.find(toupper(letra)) != freqt.end() && freqt[toupper(letra)] > 0) {
                whoops++;  // Incrementing whoops if transformation is possible
                pair.second--;  // Decrementing the count in freqs
                freqt[toupper(letra)]--;  // Decrementing the count in freqt
            } else if (isupper(letra) && islower(letra) && freqt.find(tolower(letra)) != freqt.end() && freqt[tolower(letra)] > 0) {
                whoops++;  // Incrementing whoops if transformation is possible
                pair.second--;  // Decrementing the count in freqs
                freqt[tolower(letra)]--;  // Decrementing the count in freqt
            } else {
                break;  // Breaking the loop if no more transformations are possible
            }
        }
    }

    std::cout << yay << " " << whoops << std::endl;  // Printing the final counts of yay and whoops

    return 0;
}
