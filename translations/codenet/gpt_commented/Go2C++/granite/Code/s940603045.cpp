
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define an infinite value for comparison
const int inf = INT_MAX;

// Initialize a new scanner for input
class Scanner {
private:
    string buf;
    int p;
public:
    Scanner() {
        buf = "";
        p = 0;
    }

    string next() {
        if (p >= buf.size()) {
            getline(cin, buf);
            p = 0;
        }
        int start = p;
        while (p < buf.size() && buf[p]!='') {
            p++;
        }
        string result = buf.substr(start, p - start);
        p++;
        return result;
    }

    string Line() {
        if (p < buf.size()) {
            buf = buf.substr(p);
            p = 0;
        }
        getline(cin, buf);
        return buf;
    }

    string String() {
        return next();
    }

    int Int() {
        int v;
        sscanf(next().c_str(), "%d", &v);
        return v;
    }

    vector<int> Ints(int n) {
        vector<int> r(n);
        for (int i = 0; i < n; i++) {
            r[i] = Int();
        }
        return r;
    }

    long long Int64() {
        long long v;
        sscanf(next().c_str(), "%lld", &v);
        return v;
    }

    unsigned long long Uint64() {
        unsigned long long v;
        sscanf(next().c_str(), "%llu", &v);
        return v;
    }

    double Float64() {
        double v;
        sscanf(next().c_str(), "%lf", &v);
        return v;
    }
};

int main() {
    Scanner sc;
    string N = sc.String();
    vector<int> b(N.begin(), N.end());
    int n = 0;
    for (int i = 0; i < b.size(); i++) {
        n += b[i] - '0';
    }
    int m = stoi(N);
    if (m % n == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

