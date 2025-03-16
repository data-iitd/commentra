
#include <bits/stdc++.h>
using namespace std;

int main() {
    int pya;
    cin >> pya;
    vector<string> arre;
    while (pya--) {
        string s;
        cin >> s;
        arre.push_back(s);
    }
    string oString;
    cin >> oString;
    string lowString = oString;
    transform(lowString.begin(), lowString.end(), lowString.begin(), ::tolower);
    char letter1;
    cin >> letter1;
    char letter2 = 'a';
    if (letter1 == 'a') letter2 = 'b';
    vector<int> valid(oString.length(), 0);
    set<int> setcito;
    for (string s : arre) {
        size_t pos = lowString.find(s);
        while (pos!= string::npos) {
            for (int i = pos; i < pos + s.length(); i++) {
                setcito.insert(i);
            }
            pos = lowString.find(s, pos + 1);
        }
    }
    for (int i : setcito) {
        char letter = letter1;
        if (lowString[i]!= letter1) letter = letter2;
        if (islower(oString[i])) {
            oString[i] = letter;
        } else {
            oString[i] = toupper(letter);
        }
    }
    cout << oString << endl;
    return 0;
}
//END-OF-CODE