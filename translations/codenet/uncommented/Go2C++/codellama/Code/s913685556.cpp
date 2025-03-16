
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Scanner {
public:
    Scanner() {
        r = new istream(cin.rdbuf());
        buf = new char[1000];
        p = 0;
    }
    string Next() {
        pre();
        int start = p;
        for (; p < len(buf); p++) {
            if (buf[p] == ' ') {
                break;
            }
        }
        string result = string(buf + start, p - start);
        p++;
        return result;
    }
    string NextLine() {
        pre();
        int start = p;
        p = len(buf);
        return string(buf + start, p - start);
    }
    int NextInt() {
        return stoi(Next());
    }
    long long NextInt64() {
        return stoll(Next());
    }
    double NextFloat() {
        return stod(Next());
    }
    vector<int> NextIntArray() {
        pre();
        int start = p;
        vector<int> result;
        for (; p < len(buf) + 1; p++) {
            if (p == len(buf) || buf[p] == ' ') {
                result.push_back(stoi(string(buf + start, p - start)));
                start = p + 1;
            }
        }
        return result;
    }
    vector<long long> NextInt64Array() {
        pre();
        int start = p;
        vector<long long> result;
        for (; p < len(buf) + 1; p++) {
            if (p == len(buf) || buf[p] == ' ') {
                result.push_back(stoll(string(buf + start, p - start)));
                start = p + 1;
            }
        }
        return result;
    }
    map<int, bool> NextMap() {
        pre();
        int start = p;
        map<int, bool> mp;
        for (; p < len(buf); p++) {
            if (buf[p] == ' ') {
                mp[stoi(string(buf + start, p - start))] = true;
                start = p + 1;
            }
        }
        mp[stoi(string(buf + start, p - start))] = true;
        return mp;
    }
    void pre() {
        if (p >= len(buf)) {
            readLine();
            p = 0;
        }
    }
    void readLine() {
        buf = new char[1000];
        for (; ; ) {
            cin.getline(buf, 1000);
            if (!cin.eof()) {
                break;
            }
        }
    }

private:
    istream *r;
    char *buf;
    int p;
};

int main() {
    Scanner sc;
    int A = sc.NextInt();
    int B = sc.NextInt();

    int mx = max(A + B, A - B);
    mx = max(mx, A * B);
    cout << mx << endl;
}

