
#include <iostream>
#include <string>
#include <map>

int main () {
    std::string s, t;
    std::map <char, int> freqs, freqt;

    std::cin >> s >> t;

    for (char letra : s) {
        if (freqs.find (letra)!= freqs.end ()) {
            freqs [letra] += 1;
        } else {
            freqs [letra] = 1;
        }
    }

    for (char letra : t) {
        if (freqt.find (letra)!= freqt.end ()) {
            freqt [letra] += 1;
        } else {
            freqt [letra] = 1;
        }
    }

    int yay = 0, whoops = 0;

    for (char letra : freqs.keys ()) {
        while (freqs [letra] > 0 && freqt.find (letra)!= freqt.end () && freqt [letra] > 0) {
            yay += 1;
            freqs [letra] -= 1;
            freqt [letra] -= 1;
        }
    }

    for (char letra : freqs.keys ()) {
        while (freqs [letra] > 0) {
            if (letra.islower () && freqt.find (letra.upper ())!= freqt.end () && freqt [letra.upper ()] > 0) {
                whoops += 1;
                freqs [letra] -= 1;
                freqt [letra.upper ()] -= 1;
            } else if (letra.isupper () && freqt.find (letra.lower ())!= freqt.end () && freqt [letra.lower ()] > 0) {
                whoops += 1;
                freqs [letra] -= 1;
                freqt [letra.lower ()] -= 1;
            } else {
                break;
            }
        }
    }

    std::cout << yay << " " << whoops << std::endl;

    return 0;
}
