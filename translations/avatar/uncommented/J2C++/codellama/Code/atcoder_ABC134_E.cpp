#include <iostream>
#include <map>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<int, int> map;
    while (n-- > 0) {
        int num;
        cin >> num;
        if (map.lower_bound(num) == map.end()) {
            int val = map[num] = 0;
            map[num] = ++val;
        } else {
            int key = map.lower_bound(num)->first;
            int val = map[key];
            if (val == 1) {
                map.erase(key);
            } else {
                map[key] = --val;
            }
            val = map[num] = 0;
            map[num] = ++val;
        }
    }
    int ans = 0;
    for (auto it = map.begin(); it != map.end(); it++) {
        int val = it->second;
        ans += val;
    }
    cout << ans << endl;
    return 0;
}


