#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Helper function to reverse the case of a character
char reverse(char ch) {
    if (islower(ch)) {
        return toupper(ch);
    } else {
        return tolower(ch);
    }
}

int main() {
    // Step 1: Read the input string `s` and the target string `t`.
    string s, t;
    cin >> s >> t;

    // Initialize counters for the number of replacements
    int ura = 0; // Counter for replacements in step 3
    int opa = 0; // Counter for replacements in step 4

    // Step 2: Create a frequency map `tmap` for characters in `t`.
    unordered_map<char, int> tmap;
    for (char ch : t) {
        tmap[ch]++;
    }

    // Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
    int length = s.length();
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        auto it = tmap.find(ch);
        if (it == tmap.end()) continue;
        int num = it->second;
        if (num == 1) {
            tmap.erase(it);
        } else {
            tmap[ch]--;
        }
        s[i] = 'Я';
        ura++;
    }

    // Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        char rch = reverse(ch);
        auto it = tmap.find(rch);
        if (it == tmap.end()) continue;
        int num = it->second;
        if (num == 1) {
            tmap.erase(it);
        } else {
            tmap[rch]--;
        }
        opa++;
    }

    // Step 5: Print the results `ura` and `opa`.
    cout << ura << " " << opa << endl;

    return 0;
}

// <END-OF-CODE>
