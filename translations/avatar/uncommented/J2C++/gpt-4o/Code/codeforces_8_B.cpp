#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int x = 0, y = 0, k = 0, dx, dy;
    bool flag = true;
    string s;
    vector<int> coX(101), coY(101);

    cin >> s;
    coX[k] = x;
    coY[k] = y;
    ++k;

    for (char ch : s) {
        switch (ch) {
            case 'L': --x; break;
            case 'R': ++x; break;
            case 'U': ++y; break;
            case 'D': --y; break;
        }
        coX[k] = x;
        coY[k] = y;
        ++k;
    }

    for (int i = 0; i < k - 3; ++i) {
        for (int j = i + 3; j < k; ++j) {
            dx = abs(coX[i] - coX[j]);
            dy = abs(coY[i] - coY[j]);
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    if (flag) 
        cout << "OK" << endl;
    else 
        cout << "BUG" << endl;

    return 0;
}
