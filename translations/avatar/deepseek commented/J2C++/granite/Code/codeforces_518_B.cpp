

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    
    map<char, int> tmap;
    for (int i = 0; i < t.length(); i++) {
        char ch = t[i];
        if (tmap.find(ch) == tmap.end()) {
            tmap[ch] = 1;
        } else {
            tmap[ch]++;
        }
    }
    
    int ura = 0, opa = 0;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (tmap.find(ch)!= tmap.end()) {
            int num = tmap[ch];
            if (num == 1) {
                tmap.erase(ch);
            } else {
                tmap[ch]--;
            }
            s[i] = 'Я';
            ura++;
        }
    }
    
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        char rch = (ch >= 'a' && ch <= 'z')? ch - 32 : ch + 32;
        if (tmap.find(rch)!= tmap.end()) {
            int num = tmap[rch];
            if (num == 1) {
                tmap.erase(rch);
            } else {
                tmap[rch]--;
            }
            opa++;
        }
    }
    
    cout << ura << " " << opa << endl;
    
    return 0;
}
