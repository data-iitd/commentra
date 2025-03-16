#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int ura = 0, opa = 0;
    unordered_map<char, int> tmap;
    for (char ch : t) {
        if (tmap.find(ch) == tmap.end()) {
            tmap[ch] = 1;
        } else {
            tmap[ch]++;
        }
    }
    int length = s.length();
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        auto num = tmap.find(ch);
        if (num == tmap.end()) continue;
        int inum = num->second;
        if (inum == 1) {
            tmap.erase(ch);
        } else {
            tmap[ch] = inum - 1;
        }
        s[i] = 'Я';
        ura++;
    }
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        char rch = (islower(ch)) ? toupper(ch) : tolower(ch);
        auto num = tmap.find(rch);
        if (num == tmap.end()) continue;
        int inum = num->second;
        if (inum == 1) {
            tmap.erase(rch);
        } else {
            tmap[rch] = inum - 1;
        }
        opa++;
    }
    cout << ura << " " << opa << endl;
    return 0;
}

