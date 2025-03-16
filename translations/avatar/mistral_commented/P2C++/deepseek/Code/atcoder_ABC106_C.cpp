#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <forward_list>
#include <array>
#include <sstream>
#include <functional>
#include <cassert>
#include <random>
#include <chrono>
#include <cstdint>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <complex>

using namespace std;

#define INF 1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a); i >= (b); --i)
#define FOREACH(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)

#define VI vector<int>
#define VVI vector<vector<int>>
#define VL vector<long long>
#define VVL vector<vector<long long>>
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SIZE(a) (int)(a).size()
#define SZ(a) (int)(a).size()

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void main() {
    string s;
    int k;
    cin >> s >> k;

    int l = 0;
    for (char c : s) {
        if (c != '1') {
            if (l >= k) {
                cout << 1 << endl;
            } else {
                cout << c << endl;
            }
            return;
        }
        l++;
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    main();
    return 0;
}

