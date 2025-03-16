#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

char reverse(char ch) {
    if (islower(ch)) {
        return toupper(ch);
    } else {
        return tolower(ch);
    }
}

int main() {
    string s, t;
    cin >> s >> t;

    int ura = 0;
    int opa = 0;
    unordered_map<char, int> tmap;

    for (char ch : t) {
        tmap[ch]++;
    }

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

    cout << ura << " " << opa << endl;

    return 0;
}

// <END-OF-CODE>
