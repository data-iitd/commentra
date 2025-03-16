

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    long long cnt[5] = {0};
    for (int i = 0; i < n; i++) {
        if (strings[i][0] == 'M') {
            cnt[0]++;
        } else if (strings[i][0] == 'A') {
            cnt[1]++;
        } else if (strings[i][0] == 'R') {
            cnt[2]++;
        } else if (strings[i][0] == 'C') {
            cnt[3]++;
        } else if (strings[i][0] == 'H') {
            cnt[4]++;
        }
    }
    long long res = cnt[0] * cnt[1] * cnt[2] + cnt[0] * cnt[1] * cnt[3] + cnt[0] * cnt[1] * cnt[4] + cnt[0] * cnt[2] * cnt[3] + cnt[0] * cnt[2] * cnt[4] + cnt[0] * cnt[3] * cnt[4] + cnt[1] * cnt[2] * cnt[3] + cnt[1] * cnt[2] * cnt[4] + cnt[1] * cnt[3] * cnt[4] + cnt[2] * cnt[3] * cnt[4];
    cout << res << endl;
    return 0;
}

