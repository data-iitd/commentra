#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> s;
    vector<string> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    string f = "Yes";
    for (int i = 0; i < n; ++i) {
        s[l[i]]++;
        if (s[l[i]] >= 2) {
            f = "No";
        }
        if (i > 0 && l[i-1].back() != l[i].front()) {
            f = "No";
        }
    }
    cout << f << endl;
    return 0;
}

