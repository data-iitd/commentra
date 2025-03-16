#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    string S;
    cin >> S;
    unordered_map<char, int> c;
    for (char s : S) {
        c[s]++;
    }
    set<char> Sa(S.begin(), S.end());
    if (Sa.size() != 2) {
        cout << "No" << endl;
        return 0;
    }
    for (char i : Sa) {
        if (c[i] != 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

