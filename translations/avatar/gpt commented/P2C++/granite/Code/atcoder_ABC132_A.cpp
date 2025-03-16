
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    map<char, int> c;
    for (char ch : S) {
        c[ch]++;
    }

    set<char> Sa;
    for (char ch : S) {
        Sa.insert(ch);
    }

    if (Sa.size()!= 2) {
        cout << "No" << endl;
        return 0;
    }

    for (char ch : Sa) {
        if (c[ch]!= 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
