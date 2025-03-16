
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    getline(cin, a);
    vector<char> vo = { 'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y' };
    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] =='' || a[i] == '?') {
            continue;
        } else {
            if (find(vo.begin(), vo.end(), a[i])!= vo.end()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            break;
        }
    }
    return 0;
}

