
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<c462b> cards(26);
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
        sort(cards.begin(), cards.end(), greater<c462b>());
        long long change = min(cards[25].left, k - i);
        ans += change * change;
        cards[25].left -= change;
        i += change - 1;
    }

    cout << ans << "\n";
}

