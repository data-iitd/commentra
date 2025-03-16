#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const long long INF = numeric_limits<long long>::max();

class Scanner {
public:
    Scanner() : buf(nullptr), p(0) {
        buf.resize(10000);
        readLine();
    }

    string next() {
        pre();
        int start = p;
        while (p < buf.size() && buf[p] != ' ') {
            p++;
        }
        string result = string(buf.begin() + start, buf.begin() + p);
        p++;
        return result;
    }

    string line() {
        pre();
        int start = p;
        p = buf.size();
        return string(buf.begin() + start, buf.end());
    }

    string string() {
        return next();
    }

    int Int() {
        return stoi(next());
    }

    vector<int> Ints(int n) {
        vector<int> r(n);
        for (int i = 0; i < n; i++) {
            r[i] = Int();
        }
        return r;
    }

    long long Int64() {
        return stoll(next());
    }

    unsigned long long Uint64() {
        return stoull(next());
    }

    double Float64() {
        return stod(next());
    }

private:
    vector<char> buf;
    int p;

    void pre() {
        if (p >= buf.size()) {
            readLine();
            p = 0;
        }
    }

    void readLine() {
        buf.resize(0);
        while (true) {
            char ch;
            cin.get(ch);
            if (ch == '\n') {
                break;
            }
            buf.push_back(ch);
        }
    }
};

Scanner next = Scanner();

int main() {
    string N = next.string();
    vector<char> b(N.begin(), N.end());
    int n = 0;

    for (char c : b) {
        n += c - '0';
    }
    int m = stoi(N);
    if (m % n == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
