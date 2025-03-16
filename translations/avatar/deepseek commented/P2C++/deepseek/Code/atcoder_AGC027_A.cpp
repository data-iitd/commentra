#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    auto na = []() {
        vector<int> v;
        int num;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while (ss >> num) {
            v.push_back(num);
        }
        return v;
    };

    vector<int> nx = na();
    int n = nx[0];
    int x = nx[1];

    vector<int> a = na();
    sort(a.begin(), a.end());

    int ans = 0;

    if (a[0] > x) {
        cout << 0 << endl;
        return 0;
    }

    for (int i : a) {
        if (i > x) {
            x = 0;
            break;
        }
        x -= i;
        ans += 1;
    }

    if (x != 0) {
        ans -= 1;
    }

    cout << ans << endl;

    return 0;
}
