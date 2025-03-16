
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int ans = A - 2 * B;
    if (ans < 0) {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}

