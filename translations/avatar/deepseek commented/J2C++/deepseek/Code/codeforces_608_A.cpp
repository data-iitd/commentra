#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits>

using namespace std;

class FastScanner {
public:
    FastScanner() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
    }

    string next() {
        string token;
        cin >> token;
        return token;
    }

    string nextLine() {
        string line;
        getline(cin, line);
        return line;
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    double nextDouble() {
        return stod(next());
    }

    char nextChar() {
        return next()[0];
    }
};

int main() {
    FastScanner in;
    int n = in.nextInt();
    int s = in.nextInt();
    int max = 0;

    for (int i = 0; i < n; ++i) {
        int f = in.nextInt();
        int t = in.nextInt();
        max = max < f + t ? f + t : max;
    }

    cout << max(max, s) << '\n';
    return 0;
}

