
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <set>
#include <map>
#include <numeric>
#include <sstream>
#include <queue>
#include <stack>
#include <iomanip>
#include <functional>
#define ll long long
using namespace std;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll A, B, K;
    cin >> A >> B >> K;
    ll x = A, y = B;
    x = A - K;
    if (x < 0) {
        y = B + x;
        x = 0;
        if (y < 0) {
            y = 0;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}
