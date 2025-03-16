
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n << endl;
    int m = n;
    for (int i = n - 1; i > 0; i--) {
        if (m % i == 0) {
            cout << i << endl;
            m = i;
        }
    }
    return 0;
}

