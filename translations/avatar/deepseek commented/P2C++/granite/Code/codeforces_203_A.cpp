

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    vector<string> xxs = split(line, " ");
    int x = stoi(xxs[0]);
    int t = stoi(xxs[1]);
    int a = stoi(xxs[2]);
    int b = stoi(xxs[3]);
    int da = stoi(xxs[4]);
    int db = stoi(xxs[5]);

    if (x == 0) {
        cout << "YES" << endl;
        return 0;
    }

    int a_time = min(a / da, t - 1);
    int b_time = min(b / db, t - 1);

    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
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

