
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

struct c462b {
    int left;
    bool operator<(const c462b &o) const {
        return left < o.left;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    c462b cards[26];
    for (int i = 0; i < 26; i++) {
        cards[i].left = 0;
    }
    string s;
    cin >> s;
    for (int t = 0; t < n; t++) {
        cards[s[t] - 'A'].left++;
    }
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        sort(cards, cards + 26);
        long long change = min(cards[25].left, k - i);
        ans += change * change;
        cards[25].left -= change;
        i += change - 1;
    }
    cout << ans << endl;
    return 0;
}

