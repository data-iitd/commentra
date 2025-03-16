#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::unordered_map<char, int> freqs;
    std::unordered_map<char, int> freqt;
    int yay = 0, whoops = 0;

    for (char letra : s) {
        freqs[letra]++;
    }

    for (char letra : t) {
        freqt[letra]++;
    }

    for (const auto& pair : freqs) {
        char letra = pair.first;
        while (freqs[letra] > 0 && freqt.count(letra) > 0 && freqt[letra] > 0) {
            yay++;
            freqs[letra]--;
            freqt[letra]--;
        }
    }

    for (const auto& pair : freqs) {
        char letra = pair.first;
        while (freqs[letra] > 0) {
            if (islower(letra) && freqt.count(toupper(letra)) > 0 && freqt[toupper(letra)] > 0) {
                whoops++;
                freqs[letra]--;
                freqt[toupper(letra)]--;
            } else if (isupper(letra) && freqt.count(tolower(letra)) > 0 && freqt[tolower(letra)] > 0) {
                whoops++;
                freqs[letra]--;
                freqt[tolower(letra)]--;
            } else {
                break;
            }
        }
    }

    std::cout << yay << " " << whoops << std::endl;

    return 0;
}

// <END-OF-CODE>
