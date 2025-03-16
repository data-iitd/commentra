
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Scanner {
public:
    Scanner() {
        r = new istream(cin.rdbuf());
        buf = new char[1000];
        p = 0;
    }
    string next() {
        pre();
        int start = p;
        for (; p < len(buf); p++) {
            if (buf[p] == ' ') {
                break;
            }
        }
        string result = string(buf[start:p]);
        p++;
        return result;
    }
    string nextLine() {
        pre();
        int start = p;
        p = len(buf);
        return string(buf[start:]);
    }
    int nextInt() {
        return stoi(next());
    }
    vector<int> nextIntArray() {
        pre();
        int start = p;
        vector<int> result;
        for (; p < len(buf) + 1; p++) {
            if (p == len(buf) || buf[p] == ' ') {
                int v = stoi(string(buf[start:p]));
                result.push_back(v);
                start = p + 1;
            }
        }
        return result;
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
            string l;
            getline(*r, l);
            buf = l.c_str();
            if (!r->good()) {
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
    Scanner sc = Scanner();
    string S = sc.next();
    if (S.find("YAKI") == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

