#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

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
    
    // Initialize counters for the number of replacements
    int ura = 0; // Counter for replacements in step 3
    int opa = 0; // Counter for replacements in step 4
    
    // Step 2: Create a frequency map `tmap` for characters in `t`.
    unordered_map<char, int> tmap;
    for (char ch : t) {
        tmap[ch]++;
    }
    
    // Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
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
    
    // Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
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
    
    // Step 5: Print the results `ura` and `opa`.
    cout << ura << " " << opa << endl;
    
    return 0;
}

