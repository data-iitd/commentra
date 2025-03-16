#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define INF 1e9
#define PI 3.1415926535897932384626433832795

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef set<int> si;

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

// Function to take input as an integer
int inp() {
    int x;
    cin >> x;
    return x;
}

// Function to take input as a list
vi inpl() {
    vi x;
    int n;
    cin >> n;
    REP(i, n) {
        int y;
        cin >> y;
        x.push_back(y);
    }
    return x;
}

// Input the number of nodes, starting and ending nodes
int n, ta, ao;
cin >> n >> ta >> ao;
ta--; ao--;

// Initialize an adjacency list
vvi g(n);

// Read edges and add them to the graph
for(int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
}

// Initialize distance arrays for both nodes
vi ta_dist(n, -1);
vi ao_dist(n, -1);

// Initialize distances for starting and ending nodes
ta_dist[ta] = 0;
ao_dist[ao] = 0;

// Depth First Search from starting node to calculate distances from starting node
function<void(int)> ta_dfs = [&](int node) {
    for(int v : g[node]) {
        if(ta_dist[v] != -1) continue;
        ta_dist[v] = ta_dist[node] + 1;
        ta_dfs(v);
    }
};

// Depth First Search from ending node to calculate distances from ending node
function<void(int)> ao_dfs = [&](int node) {
    for(int v : g[node]) {
        if(ao_dist[v] != -1) continue;
        ao_dist[v] = ao_dist[node] + 1;
        ao_dfs(v);
    }
};

// Perform Depth First Search from starting and ending nodes
ta_dfs(ta);
ao_dfs(ao);

// Calculate the answer
int res = 0;
for(int i = 0; i < n; i++) {
    if(ta_dist[i] == -1 || ao_dist[i] == -1 || ta_dist[i] > ao_dist[i]) continue;
    res = max(res, ao_dist[i]);
}

// Print the answer
cout << res - 1 << endl;

