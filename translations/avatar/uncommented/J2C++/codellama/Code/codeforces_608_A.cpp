
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cassert>
using namespace std;

class FastScanner {
public:
    FastScanner() {
        cin.tie(NULL);
        ios::sync_with_stdio(false);
    }

    string next() {
        string str;
        cin >> str;
        return str;
    }

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        cin >> x;
        return x;
    }

    double nextDouble() {
        double x;
        cin >> x;
        return x;
    }
};

int main() {
    FastScanner in;
    int n = in.nextInt();
    int s = in.nextInt();
    int max = 0;
    while (n-- > 0) {
        int f = in.nextInt();
        int t = in.nextInt();
        if (max < f + t) {
            max = f + t;
        }
    }
    cout << max << endl;
    return 0;
}

