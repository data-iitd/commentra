
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <numeric>
#include <sstream>
#include <queue>
#include <iomanip>
#include <stack>
#include <limits>
#include <cassert>
#include <bitset>
#include <functional>
#include <random>

using namespace std;

using lint = long long;
using ll = long long;
using ld = long double;

class Scanner {
public:
    Scanner() {
        rdr = new BufferedReader(new InputStreamReader(System.in));
        buf = new StringBuilder();
        p = 0;
    }

    string Next() {
        pre();
        start = p;
        for (; p < buf.length(); p++) {
            if (buf.charAt(p) =='') {
                break;
            }
        }
        string result = buf.substring(start, p);
        p++;
        return result;
    }

    string NextLine() {
        pre();
        start = p;
        p = buf.length();
        return buf.substring(start);
    }

    int NextInt() {
        return Integer.parseInt(Next());
    }

    int NextInt64() {
        return Integer.parseInt(Next());
    }

    float NextFloat() {
        return Float.parseFloat(Next());
    }

    vector<int> NextIntArray() {
        pre();
        start = p;
        vector<int> result;
        for (; p < buf.length() + 1; p++) {
            if (p == buf.length() || buf.charAt(p) =='') {
                result.push_back(Integer.parseInt(buf.substring(start, p)));
                start = p + 1;
            }
        }
        return result;
    }

    vector<int64_t> NextInt64Array() {
        pre();
        start = p;
        vector<int64_t> result;
        for (; p < buf.length() + 1; p++) {
            if (p == buf.length() || buf.charAt(p) =='') {
                result.push_back(Long.parseLong(buf.substring(start, p)));
                start = p + 1;
            }
        }
        return result;
    }

    map<int, bool> NextMap() {
        pre();
        start = p;
        map<int, bool> mp;
        for (; p < buf.length(); p++) {
            if (buf.charAt(p) =='') {
                mp[Integer.parseInt(buf.substring(start, p))] = true;
                start = p + 1;
            }
        }
        mp[Integer.parseInt(buf.substring(start, p))] = true;

        return mp;
    }

private:
    BufferedReader *rdr;
    StringBuilder *buf;
    int p;
    int start;

    void pre() {
        if (p >= buf.length()) {
            readLine();
            p = 0;
        }
    }

    void readLine() {
        buf->setLength(0);
        string line;
        while (getline(*rdr, line)) {
            buf->append(line);
            buf->append("\n");
        }
    }
};

int main() {
    Scanner sc;
    int H = sc.NextInt();
    int W = sc.NextInt();
    int N = sc.NextInt();
    int A = max(H, W);
    cout << (N + A - 1) / A << endl;
    return 0;
}

// 