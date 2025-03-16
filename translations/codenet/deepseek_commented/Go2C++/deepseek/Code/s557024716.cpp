#include <bits/stdc++.h>
using namespace std;

#define DEBUG
#ifdef DEBUG
#define Print(...) { print(#__VA_ARGS__, __VA_ARGS__); }
#else
#define Print(...)
#endif
template<typename T>
void print(string_view name, T value) {
    cerr << name << " = " << value << endl;
}
template<typename T, typename... Args>
void print(string_view names, T value, Args... args) {
    string_view name = names.substr(0, names.find(','));
    cerr << name << " = " << value << ", ";
    print(names.substr(name.size() + 1), args...);
}

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

using ll = long long;
constexpr ll MOD = 1000000000 + 7;
constexpr ll ALPHABET_NUM = 26;
constexpr ll INF_INT64 = numeric_limits<int64_t>::max();
constexpr ll INF_BIT60 = 1LL << 60;
constexpr ll INF_INT32 = numeric_limits<int32_t>::max();
constexpr ll INF_BIT30 = 1 << 30;
constexpr ll NIL = -1;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    init();

    int a, b, c;
    int k;
    cin >> a >> b >> c >> k;

    vector<vector<int>> patterns;
    function<void(vector<int>&, int)> generate = [&](vector<int>& pattern, int depth) {
        if (depth == k) {
            patterns.push_back(pattern);
            return;
        }
        for (int i = 0; i < 4; ++i) {
            pattern.push_back(i);
            generate(pattern, depth + 1);
            pattern.pop_back();
        }
    };

    vector<int> initial_pattern;
    generate(initial_pattern, 0);

    for (const auto& P : patterns) {
        int r = a, g = b, _ = c;
        for (int i = 0; i < k; ++i) {
            if (P[i] == 0) continue;
            if (P[i] == 1) r *= 2;
            else if (P[i] == 2) g *= 2;
            else if (P[i] == 3) _ *= 2;
        }
        if (g > r && _ > g) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
