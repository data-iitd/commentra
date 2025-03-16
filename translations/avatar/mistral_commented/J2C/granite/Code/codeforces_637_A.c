

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

#ifdef DEBUG
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...) // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator, (const T& v){
        cerr<<v<<" ";
        return *this;
    }
} dbg;

int main() {
    int n;
    cin >> n;
    vector<int> ara(n);
    map<int, int> map;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        ara[i] = v;
        if (map.find(v) == map.end()) {
            map[v] = 1;
        } else {
            map[v]++;
        }
    }
    int max = 0;
    for (auto it : map) {
        max = max(max, it.second);
    }
    map<int, int> mm;
    for (int i = 0; i < n; i++) {
        if (mm.find(ara[i]) == mm.end()) {
            mm[ara[i]] = 1;
            if (mm[ara[i]] == max) {
                cout << ara[i] << endl;
                break;
            }
        } else {
            mm[ara[i]]++;
            if (mm[ara[i]] == max) {
                cout << ara[i] << endl;
                break;
            }
        }
    }
    return 0;
}

