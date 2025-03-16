

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>
#include <iomanip>
#include <stack>
#include <bitset>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int count = 0;
    while (a > 0 && b > 0) {
        count++;
        a--;
        b--;
    }
    int ans = a / 2 + b / 2;
    cout << count << " " << ans << endl;
    return 0;
}
