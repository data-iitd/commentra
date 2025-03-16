#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;

    while (n--) {
        int num;
        cin >> num;

        if (mp.lower_bound(num) == mp.end()) {
            mp[num]++;
        } else {
            int key = *mp.lower_bound(num);
            mp[key]--;
            if (mp[key] == 0) {
                mp.erase(key);
            }
            mp[num]++;
        }
    }

    int ans = 0;
    for (auto it : mp) {
        ans += it.second;
    }

    cout << ans << endl;

    return 0;
}

