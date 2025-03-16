
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <tuple>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    string s = "";
    while (N > 0) {
        s = to_string(N % K) + s;
        N /= K;
    }

    cout << s.length() << endl;

    return 0;
}

// 