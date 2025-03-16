#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class c462b {
public:
    int left = 0;

    bool operator<(const c462b& other) const {
        return left < other.left;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<c462b> cards(26);

    string s;
    cin >> s;

    for (char ch : s) {
        cards[ch - 'A'].left++;
    }

    long long ans = 0;
    for (int i = 0; i < k; i++) {
        sort(cards.begin(), cards.end());
        long long change = min(cards[25].left, k - i);
        ans += change * change;
        cards[25].left -= change;
        i += change - 1;
    }

    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
