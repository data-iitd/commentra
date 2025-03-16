#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

struct Card {
    int left = 0;

    bool operator<(const Card& other) const {
        return left > other.left;
    }
};

int main() {
    int n, k;
    string s;
    cin >> n >> k;
    cin.ignore(); // Ignore the newline character after reading n and k
    getline(cin, s);

    vector<Card> cards(26);
    for (int i = 0; i < n; ++i) {
        cards[s[i] - 'A'].left++;
    }

    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        sort(cards.begin(), cards.end());
        long long change = min(static_cast<long long>(cards[25].left), static_cast<long long>(k - i));
        ans += change * change;
        cards[25].left -= change;
        i += change - 1;
    }

    cout << ans << endl;
    return 0;
}

