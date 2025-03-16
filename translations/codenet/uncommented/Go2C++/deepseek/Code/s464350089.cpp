#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>

using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, n;
    cin >> h >> n;
    int a = 0;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a += temp;
    }

    if (h > a) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
