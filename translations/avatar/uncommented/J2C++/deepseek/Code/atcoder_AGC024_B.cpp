#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        P[i]--;
    }
    map<int, int> map;
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i;
    }
    list<int> nglist;
    for (int i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist.push_back(i);
        }
    }
    if (nglist.empty()) {
        cout << 0 << endl;
        return 0;
    }
    int ans = min(N - nglist.front() - 1, nglist.back() + 1);
    auto it = nglist.begin();
    for (int i = 0; i < nglist.size() - 1; ++i) {
        ans = min(nglist.front() + 1 + N - nglist.back() - 1, ans);
        ++it;
    }
    cout << ans << endl;
    return 0;
}

