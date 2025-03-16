#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    int pya;
    cin >> pya;
    vector<string> arre;
    while (pya) {
        pya--;
        arre.push_back(cin.get());
    }
    string oString;
    cin >> oString;
    string lowString = oString;
    for (int i = 0; i < lowString.length(); i++) {
        lowString[i] = tolower(lowString[i]);
    }
    char letter1;
    cin >> letter1;
    char letter2 = 'a' if letter1!= 'a' else 'b';
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
        char letter = letter1 if lowString[i]!= letter1 else letter2;
        oString[i] = letter if oString[i]!= letter1 else letter;
    }
    for (char x : oString) {
        cout << x;
    }
    cout << endl;
    return 0;
}

