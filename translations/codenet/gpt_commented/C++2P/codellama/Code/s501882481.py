#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define MAX (1 << 29)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

#define to_string(s) s
#define to_string(p) "{" + to_string(p.first) + "," + to_string(p.second) + "}"
#define to_string(v) "{" + to_string(v[0]) + ", " + to_string(v[1]) + ", " + to_string(v[2]) + "}"

#define debug() cerr << endl
#define debug(head, tail...) cerr << to_string(head) << " " << to_string(tail) << endl
#define print() cout << endl
#define print(head, tail...) cout << to_string(head) << " " << to_string(tail) << endl
#define get()
#define get(head, tail...) cin >> head >> tail
#define getv(vec) for (int i = 0; i < vec.size(); ++i) cin >> vec[i]

int main() {
    string S;
    cin >> S;

    if (S == "Sunny") {
        print("Cloudy");
    } else if (S == "Cloudy") {
        print("Rainy");
    } else {
        print("Sunny");
    }

    return 0;
}

