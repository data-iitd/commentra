#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <utility>
#include <climits>
#include <numeric>
#include <stack>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ld long double
#define PB push_back
#define PF push_front
#define MP make_pair
#define rep(i, a, b) for(int i = a; i < b; i++)
#define drep(i, a, b) for(int i = a; i > b; i--)
#define fori(a) for(auto i : a)
#define sorti(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.rbegin(), a.rend())
#define MOD 1000000007

int main() {
    string s;
    cin >> s;
    int pp = 0, na = 0;
    for(int i = s.length() - 1; i >= 0; i--) {
        int cc = na + (s[i] - '0');
        na = 0;
        if(cc <= 4) {
            pp += cc;
        } else {
            na = 1;
            if(i == 0) {
                pp += 1;
            } else {
                pp += 10 - cc;
            }
        }
    }
    cout << pp << endl;
    return 0;
}

