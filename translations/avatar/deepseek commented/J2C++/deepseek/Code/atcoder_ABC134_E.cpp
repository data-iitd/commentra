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
            map[num]++;
        } else {
            auto it = map.lower_bound(num);
            it--;
            int key = it->first;
            map[key]--;
            if (map[key] == 0) {
                map.erase(key);
            }
            map[num]++;
        }
    }

    int ans = 0;
    for (auto& pair : map) {
        ans += pair.second;
    }

    cout << ans << endl;
    return 0;
}

