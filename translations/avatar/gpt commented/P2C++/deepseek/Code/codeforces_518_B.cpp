#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::unordered_map<char, int> freqs;
    std::unordered_map<char, int> freqt;

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
        int count = pair.second;
        if (freqt.find(letra) != freqt.end()) {
            int min_count = std::min(count, freqt[letra]);
            yay += min_count;
            freqs[letra] -= min_count;
            freqt[letra] -= min_count;
        }
    }

    // Compare remaining characters for case-insensitive matches
    for (auto& pair : freqs) {
        char letra = pair.first;
        int count = pair.second;
        if (count > 0) {
            if (letra >= 'a' && letra <= 'z') {
                char upper_letra = letra - 'a' + 'A';
                if (freqt.find(upper_letra) != freqt.end() && freqt[upper_letra] > 0) {
                    int min_count = std::min(count, freqt[upper_letra]);
                    whoops += min_count;
                    freqs[letra] -= min_count;
                    freqt[upper_letra] -= min_count;
                }
            } else if (letra >= 'A' && letra <= 'Z') {
                char lower_letra = letra - 'A' + 'a';
                if (freqt.find(lower_letra) != freqt.end() && freqt[lower_letra] > 0) {
                    int min_count = std::min(count, freqt[lower_letra]);
                    whoops += min_count;
                    freqs[letra] -= min_count;
                    freqt[lower_letra] -= min_count;
                }
            }
        }
    }

    // Print the results: number of exact matches and case-insensitive matches
    std::cout << yay << " " << whoops << std::endl;

    return 0;
}
