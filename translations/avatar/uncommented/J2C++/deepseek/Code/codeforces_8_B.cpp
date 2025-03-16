#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> x_coords, y_coords;
    int x = 0, y = 0;
    x_coords.push_back(x);
    y_coords.push_back(y);

    for (char c : s) {
        switch (c) {
            case 'L': --x; break;
            case 'R': ++x; break;
            case 'U': ++y; break;
            case 'D': --y; break;
        }
        x_coords.push_back(x);
        y_coords.push_back(y);
    }

    bool flag = true;
    for (int i = 0; i < x_coords.size() - 3; ++i) {
        for (int j = i + 3; j < x_coords.size(); ++j) {
            int dx = x_coords[i] - x_coords[j];
            int dy = y_coords[i] - y_coords[j];
            if (dx < 0) dx = -dx;
            if (dy < 0) dy = -dy;
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    if (flag) cout << "OK" << endl;
    else cout << "BUG" << endl;

    return 0;
}
