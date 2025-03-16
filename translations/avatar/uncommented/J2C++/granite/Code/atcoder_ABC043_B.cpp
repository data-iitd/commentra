
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string d = "";
    for (char c : s) {
        switch (c) {
            case '0':
                d += "0";
                break;
            case '1':
                d += "1";
                break;
            case 'B':
                if (d.length() > 0) {
                    d.pop_back();
                }
                break;
        }
    }
    cout << d << endl;
    return 0;
}
//END-OF-CODE