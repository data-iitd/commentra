
#include <bits/stdc++.h>
using namespace std;

int main() {
    int pya;
    cin >> pya;
    vector<string> arre;
    while (pya) {
        pya--;
        string s;
        cin >> s;
        arre.push_back(s);
    }
    string oString;
    cin >> oString;
    string lowString = oString;
    for (int i = 0; i < lowString.length(); i++) {
        lowString[i] = tolower(lowString[i]);
    }
    string letter1 = oString[0];
    string letter2 = 'a';
    if (letter1!= 'a') {
        letter2 = 'b';
    }
    vector<int> valid(oString.length(), 0);
    set<int> setcito;
    for (string x : arre) {
        int wat = 0;
        while (true) {
            int index = lowString.find(x, wat);
            if (index < 0) {
                break;
            }
            for (int i = index; i < index + x.length(); i++) {
                setcito.insert(i);
            }
            wat = index + 1;
        }
    }
    for (int i : setcito) {
        if (lowString[i]!= letter1) {
            letter2 = 'a';
        } else {
            letter2 = 'b';
        }
        if (oString[i] >= 'a' && oString[i] <= 'z') {
            oString[i] = letter2;
        } else {
            oString[i] = letter2.upper();
        }
    }
    for (char x : oString) {
        cout << x;
    }
    cout << endl;
    return 0;
}

