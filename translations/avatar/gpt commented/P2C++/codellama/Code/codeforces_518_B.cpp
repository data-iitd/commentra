#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    unordered_map<char, int> freqs, freqt;
    int yay = 0, whoops = 0;

    for (char letra : s) {
        if (freqs.find(letra) != freqs.end()) {
            freqs[letra]++;
        } else {
            freqs[letra] = 1;
        }
    }

    for (char letra : t) {
        if (freqt.find(letra) != freqt.end()) {
            freqt[letra]++;
        } else {
            freqt[letra] = 1;
        }
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
            if (letra.first.islower() && freqt.find(letra.first.upper()) != freqt.end() && freqt[letra.first.upper()] > 0) {
                whoops++;
                freqs[letra.first]--;
                freqt[letra.first.upper()]--;
            } else if (letra.first.isupper() && freqt.find(letra.first.lower()) != freqt.end() && freqt[letra.first.lower()] > 0) {
                whoops++;
                freqs[letra.first]--;
                freqt[letra.first.lower()]--;
            } else {
                break;
            }
        }
    }

    cout << yay << " " << whoops << endl;

    return 0;
}

