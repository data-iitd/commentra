
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

class Scanner {
private:
    vector<string> buf;
    int cur;
    FILE *r;

public:
    Scanner() {
        buf.clear();
        cur = 0;
        r = stdin;
    }

    void readln() {
        char buf[1000];
        fgets(buf, 1000, r);
        string s = buf;
        buf.clear();
        int len = s.length();
        int i = 0;
        while (i < len) {
            if (s[i] =='') {
                buf.push_back(s.substr(0, i));
                s = s.substr(i + 1, len - i - 1);
                len = s.length();
                i = 0;
            } else {
                i++;
            }
        }
        if (len > 0) {
            buf.push_back(s);
        }
        cur = 0;
    }

    bool isFull() {
        return cur == buf.size();
    }

    void resetCur() {
        cur = 0;
    }

    string next() {
        if (cur == 0) {
            readln();
        }
        string res = buf[cur];
        cur++;
        if (isFull()) {
            resetCur();
        }
        return res;
    }

    vector<string> nexts() {
        readln();
        resetCur();
        return buf;
    }

    int nextInt() {
        if (cur == 0) {
            readln();
        }
        int res;
        sscanf(buf[cur].c_str(), "%d", &res);
        cur++;
        if (isFull()) {
            resetCur();
        }
        return res;
    }

    vector<int> nextInts() {
        readln();
        vector<int> res;
        for (int i = 0; i < buf.size(); i++) {
            int tmp;
            sscanf(buf[i].c_str(), "%d", &tmp);
            res.push_back(tmp);
        }
        resetCur();
        return res;
    }

    float nextFloat() {
        if (cur == 0) {
            readln();
        }
        float res;
        sscanf(buf[cur].c_str(), "%f", &res);
        cur++;
        if (isFull()) {
            resetCur();
        }
        return res;
    }

    vector<float> nextFloats() {
        readln();
        vector<float> res;
        for (int i = 0; i < buf.size(); i++) {
            float tmp;
            sscanf(buf[i].c_str(), "%f", &tmp);
            res.push_back(tmp);
        }
        resetCur();
        return res;
    }

    int digits(int x) {
        return to_string(x).length();
    }

    int powInt(int x, int p) {
        int res = 1;
        for (int i = 0; i < p; i++) {
            res *= x;
        }
        return res;
    }

    int max(int x, int y) {
        return max(x, y);
    }

    int min(int x, int y) {
        return min(x, y);
    }

    int abs(int x) {
        return abs(x);
    }

    void varDump(vector<int> value) {
        for (int i = 0; i < value.size(); i++) {
            cerr << value[i] << endl;
        }
    }

    void yes() {
        cout << "Yes" << endl;
    }

    void no() {
        cout << "No" << endl;
    }
};

int main() {
    Scanner sc;
    int A = sc.nextInt();
    int B = sc.nextInt();
    if ((A + B) % 2 == 0) {
        cout << (A + B) / 2 << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

