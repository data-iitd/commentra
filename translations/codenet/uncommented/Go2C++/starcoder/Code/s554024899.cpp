#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <bitset>
#include <complex>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <ctime>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int> >
#define vvl vector<vector<long long> >
#define vvc vector<vector<char> >
#define vvs vector<vector<string> >
#define vvb vector<vector<bool> >
#define pqb priority_queue<int>
#define pql priority_queue<long long>
#define pqi priority_queue<pii>
#define pql priority_queue<pll>
#define pqs priority_queue<string>
#define pqa priority_queue<pii, vii>
#define pql priority_queue<pll, vll>
#define pqs priority_queue<string, vqs>
#define pqv priority_queue<int, vqi, greater<int> >
#define pql priority_queue<long long, vql, greater<long long> >
#define pqi priority_queue<pii, vqi, greater<pii> >
#define pql priority_queue<pll, vql, greater<pll> >
#define pqs priority_queue<string, vqs, greater<string> >
#define pqvs priority_queue<vector<int>, vqs>
#define pqvl priority_queue<vector<long long>, vqs>
#define pqvc priority_queue<vector<char>, vqs>
#define pqvs priority_queue<vector<string>, vqs>
#define pqvb priority_queue<vector<bool>, vqs>
#define pqpi priority_queue<pii, vqs>
#define pqpl priority_queue<pll, vqs>
#define pqss priority_queue<string, vqs>
#define pqsi priority_queue<string, vqs, greater<string> >
#define pqsci priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, int> > >
#define pqscd priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, double> > >
#define pqsci priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, char> > >
#define pqscf priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, float> > >
#define pqsc priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii> > >
#define pqsls priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pll> > >
#define pqscs priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, string> > >
#define pqsb priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, bool> > >
#define pqsii priority_queue<string, vqs, greater<string>, \
	allocator<pair<const string, pii