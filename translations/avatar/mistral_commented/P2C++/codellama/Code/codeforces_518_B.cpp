#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main () {
    // We start by defining two empty dictionaries to store the frequency of each character in the strings s and t respectively
    unordered_map <char, int> freqs;
    unordered_map <char, int> freqt;

    // We read the two strings s and t from the user input
    string s, t;
    cin >> s >> t;

    // We iterate through each character in the string s and update the frequency count in the freqs dictionary
    for (int i = 0; i < s.length (); i++) {
        if (freqs.find (s [i]) != freqs.end ()) {
            freqs [s [i]] += 1;
        } else {
            freqs [s [i]] = 1;
        }
    }

    // We iterate through each character in the string t and update the frequency count in the freqt dictionary
    for (int i = 0; i < t.length (); i++) {
        if (freqt.find (t [i]) != freqt.end ()) {
            freqt [t [i]] += 1;
        } else {
            freqt [t [i]] = 1;
        }
    }

    // We initialize two counters, yay and whoops, to zero
    int yay = 0, whoops = 0;

    // We iterate through each character in the freqs dictionary and check if its frequency is greater than zero and if it is present in the freqt dictionary with a frequency greater than zero. If both conditions are true, we increment the yay counter
    for (auto it = freqs.begin (); it != freqs.end (); it++) {
        while (it->second > 0 and freqt.find (it->first) != freqt.end () and freqt [it->first] > 0) {
            yay += 1;
            it->second -= 1;
            freqt [it->first] -= 1;
        }
    }

    // We iterate through each character in the freqs dictionary again and check if its frequency is greater than zero. If it is, we check if its lowercase version is present in the freqt dictionary with a frequency greater than zero or if its uppercase version is present in the freqt dictionary with a frequency greater than zero. If either condition is true, we increment the whoops counter
    for (auto it = freqs.begin (); it != freqs.end (); it++) {
        while (it->second > 0) {
            if (it->first >= 'a' and it->first <= 'z' and freqt.find (it->first - 'a' + 'A') != freqt.end () and freqt [it->first - 'a' + 'A'] > 0) {
                whoops += 1;
                it->second -= 1;
                freqt [it->first - 'a' + 'A'] -= 1;
            } else if (it->first >= 'A' and it->first <= 'Z' and freqt.find (it->first - 'A' + 'a') != freqt.end () and freqt [it->first - 'A' + 'a'] > 0) {
                whoops += 1;
                it->second -= 1;
                freqt [it->first - 'A' + 'a'] -= 1;
            } else {
                break;
            }
        }
    }

    // Finally, we print the values of yay and whoops
    cout << yay << " " << whoops << endl;

    return 0;
}

