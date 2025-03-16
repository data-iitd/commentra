
#include <bits/stdc++.h>
using namespace std;

int main() {
    string xxs;
    getline(cin, xxs);
    vector<string> xxs_splitted = split(xxs);
    int x = stoi(xxs_splitted[0]);
    int t = stoi(xxs_splitted[1]);
    int a = stoi(xxs_splitted[2]);
    int b = stoi(xxs_splitted[3]);
    int da = stoi(xxs_splitted[4]);
    int db = stoi(xxs_splitted[5]);

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

