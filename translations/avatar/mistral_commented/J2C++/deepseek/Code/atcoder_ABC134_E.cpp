#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> map;

    while (n--) {
        int num;
        cin >> num;

        if (map.lower_bound(num) == map.begin()) {
            map[num] = map.find(num) == map.end() ? 0 : map[num] + 1;
        } else {
            auto it = map.lower_bound(num);
            --it;
            int key = it->first;
            int val = it->second;

            if (val == 1) {
                map.erase(key);
            } else {
                map[key] = val - 1;
            }

            map[num] = map.find(num) == map.end() ? 0 : map[num] + 1;
        }
    }

    int ans = 0;

    for (auto& pair : map) {
        ans += pair.second;
    }

    cout << ans << endl;

