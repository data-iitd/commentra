#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> w;
    vector<int> elements(n);

    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
        w[elements[i]]++;
    }

    int c = 0;

    for (const auto& pair : w) {
        int num = pair.first;
        if (num == 0) {
            c += pair.second * (pair.second - 1);
        } else {
            if (w.find(-num) != w.end()) {
                c += pair.second * w[-num];
            }
        }
    }

    cout << c / 2 << "\n";

    return 0;
}

