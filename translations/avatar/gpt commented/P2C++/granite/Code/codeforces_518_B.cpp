
#include <iostream>
#include <string>
#include <map>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::map<char, int> freqs, freqt;

    for (char letra : s) {
        freqs[letra]++;
    }

    for (char letra : t) {
        freqt[letra]++;
    }

    int yay = 0, whoops = 0;

    for (auto it = freqs.begin(); it!= freqs.end(); ++it) {
        char letra = it->first;
        while (freqs[letra] > 0 && freqt[letra] > 0) {
            yay++;
            freqs[letra]--;
            freqt[letra]--;
        }
    }

    for (auto it = freqs.begin(); it!= freqs.end(); ++it) {
        char letra = it->first;
        while (freqs[letra] > 0) {
            if (letra >= 'a' && letra <= 'z' && freqt[letra - 'a' + 'A'] > 0) {
                whoops++;
                freqs[letra]--;
                freqt[letra - 'a' + 'A']--;
            } else if (letra >= 'A' && letra <= 'Z' && freqt[letra - 'A' + 'a'] > 0) {
                whoops++;
                freqs[letra]--;
                freqt[letra - 'A' + 'a']--;
            } else {
                break;
            }
        }
    }

    std::cout << yay << " " << whoops << std::endl;

    return 0;
}
