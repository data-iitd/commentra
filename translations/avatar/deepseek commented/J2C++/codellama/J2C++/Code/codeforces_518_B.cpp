
#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main() {
    // Step 1: Read the input string `s` and the target string `t`.
    string s, t;
    cin >> s >> t;
    
    // Initialize counters for the number of replacements
    int ura = 0; // Counter for replacements in step 3
    int opa = 0; // Counter for replacements in step 4
    
    // Step 2: Create a frequency map `tmap` for characters in `t`.
    map<char, int> tmap;
    for (int i = 0; i < t.length(); i++) {
        char ch = t[i];
        if (tmap.find(ch) == tmap.end()) {
            tmap[ch] = 1;
        } else {
            tmap[ch]++;
        }
    }
    
    // Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
    int length = s.length();
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        if (tmap.find(ch) == tmap.end()) continue;
        int inum = tmap[ch];
        if (inum == 1) {
            tmap.erase(ch);
        } else {
            tmap[ch] = inum - 1;
        }
        s[i] = 'Я';
        ura++;
    }
    
    // Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        char rch = reverse(ch);
        if (tmap.find(rch) == tmap.end()) continue;
        int inum = tmap[rch];
        if (inum == 1) {
            tmap.erase(rch);
        } else {
            tmap[rch] = inum - 1;
        }
        opa++;
    }
    
    // Step 5: Print the results `ura` and `opa`.
    cout << ura << " " << opa << endl;
    
    return 0;
}

// Helper method to reverse the case of a character
char reverse(char ch) {
    if (islower(ch)) {
        return toupper(ch);
    } else {
        return tolower(ch);
    }
}

// 