#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<char, int> freqs;
    std::unordered_map<char, int> freqt;

    std::string s, t;
    std::cin >> s >> t;

    for (char letra : s) {
        freqs[letra]++;
    }

    for (char letra : t) {
        freqt[letra]++;
    }

    int yay = 0, whoops = 0;

    for (auto& par : freqs) {
        char letra = par.first;
        while (par.second > 0 && freqt[letra] > 0) {
            yay++;
            par.second--;
            freqt[letra]--;
        }
    }

    for (auto& par : freqs) {
        char letra = par.first;
        while (par.second > 0) {
            if (islower(letra) && isupper(letra) && freqt[toupper(letra)] > 0) {
                whoops++;
                par.second--;
                freqt[toupper(letra)]--;
            } else if (isupper(letra) && islower(letra) && freqt[tolower(letra)] > 0) {
                whoops++;
                par.second--;
                freqt[tolower(letra)]--;
            } else {
                break;
            }
        }
    }

    std::cout << yay << " " << whoops << std::endl;

    return 0;
}
