#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ara(n);
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        ara[i] = v;
        map[v]++;
    }

    int max_count = 0;
    for (const auto& pair : map) {
        max_count = max(max_count, pair.second);
    }

    unordered_map<int, int> mm;
    for (int i = 0; i < n; i++) {
        if (mm[ara[i]]++ == 0) {
            if (mm[ara[i]] == max_count) {
                cout << ara[i] << endl;
                break;
            }
        }
        if (mm[ara[i]] == max_count) {
            cout << ara[i] << endl;
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
