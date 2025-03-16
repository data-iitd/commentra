#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string s;
    cin >> s;
    string d;
    for (char c : s) {
        switch (c) {
            case '0':
                d += "0";
                break;
            case '1':
                d += "1";
                break;
            case 'B':
                if (!d.empty()) {
                    d.pop_back();
                }
                break;
        }
    }
    cout << d << endl;
    return 0;
}

