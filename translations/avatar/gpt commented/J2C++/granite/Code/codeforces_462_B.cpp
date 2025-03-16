
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct c462b {
    int left;
    bool operator<(const c462b& other) const {
        return left < other.left;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<c462b> cards(26);
    for (int i = 0; i < n; i++) {
        cards[s[i] - 'A'].left++;
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

// End of C++ code