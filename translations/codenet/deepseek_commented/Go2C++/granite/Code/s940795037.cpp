
#include <bits/stdc++.h>
using namespace std;

struct Scanner {
    istream& r;
    vector<char> buf;
    int p;
    Scanner(istream& r) : r(r), p(0) {}
    string next() {
        p = 0;
        while (p < buf.size() && buf[p] =='') p++;
        int start = p;
        while (p < buf.size() && buf[p]!='') p++;
        return string(buf.begin() + start, buf.begin() + p);
    }
    string nextLine() {
        p = 0;
        while (p < buf.size() && buf[p]!= '\n') p++;
        int start = p + 1;
        while (p < buf.size() && buf[p]!= '\n') p++;
        return string(buf.begin() + start, buf.begin() + p);
    }
    int nextInt() {
        string s = next();
        int v;
        sscanf(s.c_str(), "%d", &v);
        return v;
    }
    vector<int> nextIntArray() {
        string s = next();
        s += " ";
        vector<int> result;
        while (s.size()) {
            int start = s.find(" ");
            int v;
            sscanf(s.substr(0, start).c_str(), "%d", &v);
            result.push_back(v);
            s = s.substr(start + 1);
        }
        return result;
    }
    map<int, bool> nextMap() {
        string s = next();
        s += " ";
        map<int, bool> result;
        while (s.size()) {
            int start = s.find(" ");
            int v;
            sscanf(s.substr(0, start).c_str(), "%d", &v);
            result[v] = true;
            s = s.substr(start + 1);
        }
        return result;
    }
    void readLine() {
        buf.clear();
        while (true) {
            int c = r.get();
            if (c == -1) {
                return;
            }
            buf.push_back(c);
            if (c == '\n') {
                break;
            }
        }
    }
};

int main() {
    Scanner sc(cin);
    int n = sc.nextInt();
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int tmp = 1 / sc.nextInt();
        ans += 1.0 / tmp;
    }
    cout << 1 / ans << endl;
    return 0;
}

