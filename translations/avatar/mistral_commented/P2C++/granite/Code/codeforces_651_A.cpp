

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <utility>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;

    cout << max(x + y - 3 + ((y - x) % 3 > 0), 0) << endl;

    return 0;
}

