
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <cassert>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<vvvd> vvvvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define forn(i, n) for (int i = 0; i < n; i++)
#define forab(i, a, b) for (int i = a; i <= b; i++)
#define forba(i, b, a) for (int i = b; i >= a; i--)
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define formp(i, m) for (auto i : m)
#define formpn(i, m, n) for (auto i : m) { if (i == n) break; }
#define forpq(i, q) for (auto i : q)
#define forpqa(i, q, a) for (auto i : q) { if (i == a) break; }
#define forpqn(i, q, n) for (auto i : q) { if (i == n) break; }
#define forsn(i, s, n) for (auto i : s) { if (i == n) break; }
#define forv(i, v) for (auto i : v)
#define fors(i, s) for (auto i : s)
#define forsn(i, 