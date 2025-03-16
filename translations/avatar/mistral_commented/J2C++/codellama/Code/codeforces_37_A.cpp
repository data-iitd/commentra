
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> map;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        map[val]++;
    }

    int max = INT_MIN;
    for (auto entry : map) {
        max = max(max, entry.second);
    }

    cout << max << " " << map.size() << endl;

    return 0;
}

