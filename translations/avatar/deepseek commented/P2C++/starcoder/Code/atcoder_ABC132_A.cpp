
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();
    set<char> Sa;
    for (int i = 0; i < n; i++) {
        Sa.insert(S[i]);
    }
    if (Sa.size()!= 2) {
        cout << "No" << endl;
        return 0;
    }
    for (auto i : Sa) {
        if (S.count(i)!= 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

