#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> a = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
    int xt = -1, yt = -1;
    for (int i = 0; i < a.size(); ++i) {
        for (int n : a[i]) {
            if (x == n) {
                xt = i;
            }
            if (y == n) {
                yt = i;
            }
        }
    }
    if (xt == yt) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
