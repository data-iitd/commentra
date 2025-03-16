#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    vector<string> xxs;
    string temp = "";
    for (char c : input) {
        if (c == ' ') {
            xxs.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        xxs.push_back(temp);
    }

    int x, t, a, b, da, db;
    x = stoi(xxs[0]);
    t = stoi(xxs[1]);
    a = stoi(xxs[2]);
    b = stoi(xxs[3]);
    da = stoi(xxs[4]);
    db = stoi(xxs[5]);

    if (x == 0) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i <= a / da; ++i) {
        for (int j = 0; j <= b / db; ++j) {
            if (a - da * i == x || b - db * j == x) {
                cout << "YES" << endl;
                return 0;
            }
            if ((a - da * i) + (b - db * j) == x) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
