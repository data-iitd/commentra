#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // We start by defining two empty unordered maps to store the frequency of each character in the strings s and t respectively
    std::unordered_map<char, int> freqs;
    std::unordered_map<char, int> freqt;

    // We read the two strings s and t from the user input
    std::string s, t;
    std::getline(std::cin, s);
    std::getline(std::cin, t);

    // We iterate through each character in the string s and update the frequency count in the freqs map
    for (char letra : s) {
        freqs[letra]++;
    }

    // We iterate through each character in the string t and update the frequency count in the freqt map
    for (char letra : t) {
        freqt[letra]++;
    }

    // We initialize two counters, yay and whoops, to zero
    int yay = 0, whoops = 0;

    // We iterate through each character in the freqs map and check if its frequency is greater than zero and if it is present in the freqt map with a frequency greater than zero. If both conditions are true, we increment the yay counter
    for (auto& pair : freqs) {
        char letra = pair.first;
        while (freqs[letra] > 0 && freqt[letra] > 0) {
            yay++;
            freqs[letra]--;
            freqt[letra]--;
        }
    }

    // We iterate through each character in the freqs map again and check if its frequency is greater than zero. If it is, we check if its lowercase version is present in the freqt map with a frequency greater than zero or if its uppercase version is present in the freqt map with a frequency greater than zero. If either condition is true, we increment the whoops counter
    for (auto& pair : freqs) {
        char letra = pair.first;
        while (freqs[letra] > 0) {
            if (islower(letra) && freqt[std::toupper(letra)] > 0) {
                whoops++;
                freqs[letra]--;
                freqt[std::toupper(letra)]--;
            } else if (isupper(letra) && freqt[std::tolower(letra)] > 0) {
                whoops++;
                freqs[letra]--;
                freqt[std::tolower(letra)]--;
            } else {
                break;
            }
        }
    }

    // Finally, we print the values of yay and whoops
    std::cout << yay << " " << whoops << std::endl;

    return 0;
}

// <END-OF-CODE>
