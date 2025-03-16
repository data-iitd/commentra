#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

// Function to reverse the case of a character
char reverse(char ch) {
    if (islower(ch)) {
        return toupper(ch);
    } else {
        return tolower(ch);
    }
}

int main() {
    string s;
    string t;
    cin >> s >> t;

    // Initialize counters for unique characters in the first string and opposite characters in the second string
    int ura = 0;
    int opa = 0;

    // Create an unordered_map to store the frequency of each character in the second string
    unordered_map<char, int> tmap;

    // Read the characters of the second string and store their frequencies in the unordered_map
    for (char ch : t) {
        tmap[ch]++;
    }

    // Process the first string
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        auto it = tmap.find(ch);
        if (it != tmap.end()) {
            int num = it->second;
            if (num == 1) {
                tmap.erase(it);
            } else {
                tmap[ch] = num - 1;
            }
            s[i] = 'Я';
            ura++;
        }
    }

    // Process the reversed version of the first string
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        char rch = reverse(ch);
        auto it = tmap.find(rch);
        if (it != tmap.end()) {
            int num = it->second;
            if (num == 1) {
                tmap.erase(it);
            } else {
                tmap[rch] = num - 1;
            }
            opa++;
        }
    }

    // Print the results
    cout << ura << " " << opa << endl;

    return 0;
}

