#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7; // Modulus value for calculations

string getString() {
    string s;
    getline(cin, s);
    return s;
}

int getInt() {
    int i;
    cin >> i;
    return i;
}

int calcMod(int x) {
    return x % mod;
}

int main() {
    vector<string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    string s = getString();
    int index = -1;

    for (int i = 0; i < week.size(); ++i) {
        if (week[i] == s) {
            index = i;
            break;
        }
    }

    cout << 7 - index << endl;
    return 0;
}

