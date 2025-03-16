
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 0;
    vector<int> h(n);
    vector<int> g(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> g[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (h[i] == g[j]) {
                result++;
            }
        }
    }
    cout << result << endl;
    return 0;
}
// END-OF-CODE