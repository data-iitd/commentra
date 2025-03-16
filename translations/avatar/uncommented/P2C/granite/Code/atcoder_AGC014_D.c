
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;

#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> string toString(T x) { return to_string(x); }
template<typename S, typename T> string toString(pair<S, T> p) { return "(" + toString(p.first) + "," + toString(p.second) + ")"; }
template<typename T> string toString(vector<T> v) {
    string res = "";
    FOR(i, 0, v.size()) {
        res += toString(v[i]);
        if (i!= v.size() - 1) res += " ";
    }
    return res;
}
template<typename T> string toString(vector<vector<T>> v) {
    string res = "";
    FOR(i, 0, v.size()) {
        res += toString(v[i]);
        if (i!= v.size() - 1) res += "\n";
    }
    return res;
}
template<typename T> string toString(queue<T> q) {
    string res = "";
    while (!q.empty()) {
        res += toString(q.front());
        q.pop();
        if (!q.empty()) res += " ";
    }
    return res;
}
template<typename T> string toString(priority_queue<T> q) {
    string res = "";
    while (!q.empty()) {
        res += toString(q.top());
        q.pop();
        if (!q.empty()) res += " ";
    }
    return res;
}
template<typename T> void toStream(T a) { cout << toString(a); }
template<typename S, typename T> void toStream(pair<S, T> p) { cout << toString(p); }
template<typename T> void toStream(vector<T> v) { cout << toString(v); }
template<typename T> void toStream(vector<vector<T>> v) { cout << toString(v); }
template<typename T> void toStream(queue<T> q) { cout << toString(q); }
template<typename T> void toStream(priority_queue<T> q) { cout << toString(q); }
template<typename T> void toStream(set<T> s) { cout << toString(s); }
template<typename S, typename T> void toStream(map<S, T> p) { cout << toString(p); }

void toStream() { cout << endl; }
template <typename Head, typename... Tail> void toStream(Head head, Tail... tail) {
    toStream(head);
    toStream(tail...);
}
#ifdef DEBUG
#define debug(...) { cout <<...