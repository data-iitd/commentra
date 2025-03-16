#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>
#include <bitset>
#include <cassert>
#include <numeric>
#include <complex>
#include <random>
#include <chrono>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define ssign(x) ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))
#define mod 1000000007
#define mod1 998244353
#define mod2 1000000009
#define INF 1e18
#define INFLL 1e18
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define Gamma(n) (n - 1) * Gamma(n - 1)
#define GammaL(n, m) (Gamma(n) / (m))
#define N 1000006
#define M 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vpll;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename U>
using umap = unordered_map<T, U>;

template <typename T>
using uset = unordered_set<T>;

template <typename T>
using umultiset = unordered_multiset<T>;

template <typename T, typename U>
istream &operator>>(istream &in, pair<T, U> &p)
{
    in >> p.first >> p.second;
    return in;
}

template <typename T, typename U>
ostream &operator<<(ostream &out, pair<T, U> &p)
{
    out << p.first << " " << p.second;
    return out;
}

template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &each : v)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, vector<T> &v)
{
    for (auto &each : v)
        out << each << " ";
    return out;
}

template <typename T>
istream &operator>>(istream &in, vector<vector<T>> &v)
{
    for (auto &each : v)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, vector<vector<T>> &v)
{
    for (auto &each : v)
        out << each << endl;
    return out;
}

template <typename T>
istream &operator>>(istream &in, set<T> &s)
{
    for (auto &each : s)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, set<T> &s)
{
    for (auto &each : s)
        out << each << " ";
    return out;
}

template <typename T>
istream &operator>>(istream &in, multiset<T> &s)
{
    for (auto &each : s)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, multiset<T> &s)
{
    for (auto &each : s)
        out << each << " ";
    return out;
}

template <typename T, typename U>
istream &operator>>(istream &in, map<T, U> &m)
{
    for (auto &each : m)
        in >> each;
    return in;
}

template <typename T, typename U>
ostream &operator<<(ostream &out, map<T, U> &m)
{
    for (auto &each : m)
        out << each << " ";
    return out;
}

template <typename T, typename U>
istream &operator>>(istream &in, unordered_map<T, U> &m)
{
    for (auto &each : m)
        in >> each;
    return in;
}

template <typename T, typename U>
ostream &operator<<(ostream &out, unordered_map<T, U> &m)
{
    for (auto &each : m)
        out << each << " ";
    return out;
}

template <typename T, typename U>
istream &operator>>(istream &in, unordered_multimap<T, U> &m)
{
    for (auto &each : m)
        in >> each;
    return in;
}

template <typename T, typename U>
ostream &operator<<(ostream &out, unordered_multimap<T, U> &m)
{
    for (auto &each : m)
        out << each << " ";
    return out;
}

template <typename T>
istream &operator>>(istream &in, unordered_set<T> &s)
{
    for (auto &each : s)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, unordered_set<T> &s)
{
    for (auto &each : s)
        out << each << " ";
    return out;
}

template <typename T>
istream &operator>>(istream &in, unordered_multiset<T> &s)
{
    for (auto &each : s)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, unordered_multiset<T> &s)
{
    for (auto &each : s)
        out << each << " ";
    return out;
}

template <typename T, typename U>
istream &operator>>(istream &in, pair<T, U> &p)
{
    in >> p.first >> p.second;
    return in;
}

template <typename T, typename U>
ostream &operator<<(ostream &out, pair<T, U> &p)
{
    out << p.first << " " << p.second;
    return out;
}

template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &each : v)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, vector<T> &v)
{
    for (auto &each : v)
        out << each << " ";
    return out;
}

template <typename T>
istream &operator>>(istream &in, vector<vector<T>> &v)
{
    for (auto &each : v)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, vector<vector<T>> &v)
{
    for (auto &each : v)
        out << each << endl;
    return out;
}

template <typename T>
istream &operator>>(istream &in, set<T> &s)
{
    for (auto &each : s)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, set<T> &s)
{
    for (auto &each : s)
        out << each << " ";
    return out;
}

template <typename T>
istream &operator>>(istream &in, multiset<T> &s)
{
    for (auto &each : s)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, multiset<T> &s)
{
    for (auto &each : s)
        out << each << " ";
    return out;
}

template <typename T, typename U>
istream &operator>>(istream &in, map<T, U> &m)
{
    for (auto &each : m)
        in >> each;
    return in;
}

template <typename T, typename U>
ostream &operator<<(ostream &out, map<T, U> &m)
{
    for (auto &each : m)
        out << each << " ";
    return out;
}

template <typename T, typename U>
istream &operator>>(istream &in, unordered_map<T, U> &m)
{
    for (auto &each : m)
        in >> each;
    return in;
}

template <typename T, typename U>
ostream &operator<<(ostream &out, unordered_map<T, U> &m)
{
    for (auto &each : m)
        out << each << " ";
    return out;
}

template <typename T, typename U>
istream &operator>>(istream &in, unordered_multimap<T, U> &m)
{
    for (auto &each : m)
        in >> each;
    return in;
}

template <typename T, typename U>
ostream &operator<<(ostream &out, unordered_multimap<T, U> &m)
{
    for (auto &each : m)
        out << each << " ";
    return out;
}

template <typename T>
istream &operator>>(istream &in, unordered_set<T> &s)
{
    for (auto &each : s)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, unordered_set<T> &s)
{
    for (auto &each : s)
        out << each << " ";
    return out;
}

template <typename T>
istream &operator>>(istream &in, unordered_multiset<T> &s)
{
    for (auto &each : s)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, unordered_multiset<T> &s)
{
    for (auto &each : s)
        out << each << " ";
    return out;
}

template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &each : v)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, vector<T> &v)
{
    for (auto &each : v)
        out << each << " ";
    return out;
}

template <typename T>
istream &operator>>(istream &in, vector<vector<T>> &v)
{
    for (auto &each : v)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, vector<vector<T>> &v)
{
    for (auto &each : v)
        out << each << endl;
    return out;
}

template <typename T>
istream &operator>>(istream &in, set<T> &s)
{
    for (auto &each : s)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, set<T> &s)
{
    for (auto &each : s)
        out << each << " ";
    return out;
}

template <typename T>
istream &operator>>(istream &in, multiset<T> &s)
{
    for (auto &each : s)
        in >> each;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, multiset<T> &s)
{
    for (auto &each : s)
        out << each << " ";
    return out;
}

template <typename T, typename U>
istream &operator>>(istream &in, map<T, U> &m)
{
    for (auto &each : m)
        in >> each;
    return in;
}

template <typename T, typename U>
ostream &operator<<(ostream &out, map<T, U> &m)
{
    for (auto &each : m)
        out << each << " ";
    return out;
}

template <typename T, typename U>
istream &operator>>(istream &in, unordered_map<T, U> &m)
{
    for (auto &each : m)
        in >> each;
    return in;
}

template <typename T, typename U>
ostream &operator<<(ostream &out, unordered_map<T, U> &m)
{
    for (auto &each : m)
        out << each << " ";
    return out;
}

template <typename T, typename U>
istream &operator>>(istream &in, unordered_multimap<T,