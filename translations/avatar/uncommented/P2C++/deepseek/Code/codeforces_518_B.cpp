#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::unordered_map<char, int> freqs, freqt;
    int yay = 0, whoops = 0;

    for (char letra : s) {
        freqs[letra]++;
    }
    for (char letra : t) {
        freqt[letra]++;
    }

    for (auto letra : freqs) {
        while (letra.second > 0 && freqt.find(letra.first) != freqt.end() && freqt[letra.first] > 0) {
            yay++;
            freqs[letra.first]--;
            freqt[letra.first]--;
        }
    }

    for (auto letra : freqs) {
        while (letra.second > 0) {
            if (islower(letra.first) && isupper(letra.first) && freqt.find(toupper(letra.first)) != freqt.end() && freqt[toupper(letra.first)] > 0) {
                whoops++;
                freqs[letra.first]--;
                freqt[toupper(letra.first)]--;
            } else if (isupper(letra.first) && islower(letra.first) && freqt.find(tolower(letra.first)) != freqt.end() && freqt[tolower(letra.first)] > 0) {
                whoops++;
                freqs[letra.first]--;
                freqt[tolower(letra.first)]--;
            } else {
                break;
            }
        }
    }

    std::cout << yay << " " << whoops << std::endl;
    return 0;
}
