#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Read the first string and initialize a StringBuilder with it
    string s;
    cin >> s;
    string t;
    cin >> t;
    int ura = 0;
    int opa = 0;
    map<char, int> tmap;
    for (int i = 0; i < t.length(); i++) {
        char ch = t[i];
        if (tmap.find(ch) == tmap.end()) {
            tmap[ch] = 1;
        } else {
            tmap[ch]++;
        }
    }
    int length = s.length();
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        int num = tmap[ch];
        if (num == 0) continue;
        int inum = num;
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
        char rch = tolower(ch) == ch? toupper(ch) : tolower(ch);
        int num = tmap[rch];
        if (num == 0) continue;
        int inum = num;
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

