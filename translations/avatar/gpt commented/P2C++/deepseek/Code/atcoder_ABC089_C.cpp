#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <limits>
#include <sstream>
#include <bitset>
#include <random>
#include <iterator>
#include <iomanip>

using namespace std;

#define int long long
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sort_unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());

const int INF = 1e18;
const int mod = 1e9 + 7;

vector<string> input_strings(int n) {
    vector<string> S(n);
    for (auto &s : S) {
        cin >> s;
    }
    return S;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<string> S = input_strings(N);

    vector<int> march_lis(5, 0);
    vector<char> march = {'M', 'A', 'R', 'C', 'H'};

    for (const auto &s : S) {
        char first_char = s[0];
        if (find(all(march), first_char) != march.end()) {
            march_lis[find(all(march), first_char) - march.begin()]++;
        }
    }

    int ans = 0;
    vector<int> indices = {0, 1, 2, 3, 4};
    do {
        ans += march_lis[indices[0]] * march_lis[indices[1]] * march_lis[indices[2]];
    } while (next_permutation(all(indices)));

    cout << ans << '\n';

    return 0;
}
