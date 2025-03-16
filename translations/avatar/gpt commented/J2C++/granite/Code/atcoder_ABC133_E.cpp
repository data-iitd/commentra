
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
#include <cstring>
#include <utility>
#include <numeric>
#include <cassert>
#include <iomanip>
#include <bitset>
#include <list>
#include <random>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, n) for (int i = a; i < (n); i++)
#define MP make_pair
#define pb push_back
#define MOD 100000007
#define EPS 1e-10

struct Node {
    int index;
    vector<int> children;
    int parent = -1;
    ll pattern = 0;
};

void setParent(int K, int parent, int use, vector<Node>& nodes) {
    nodes[use].pattern = K - use;
    nodes[use].parent = parent;
    int count = 1;
    if (parent!= -1) {
        count++;
    }
    for (int n : nodes[use].children) {
        if (n == parent) {
            continue;
        }
        setParent(K, use, n, nodes);
        count++;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<Node> nodes(N);
    REP(i, N) {
        nodes[i].index = i;
    }
    REP(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        nodes[a].children.pb(b);
        nodes[b].children.pb(a);
    }
    setParent(K, -1, 0, nodes);
    ll patterns = 1;
    REP(i, N) {
        patterns = (patterns * nodes[i].pattern) % MOD;
    }
    cout << patterns << endl;
    return 0;
}

