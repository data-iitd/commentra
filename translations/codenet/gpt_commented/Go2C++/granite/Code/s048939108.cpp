
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

struct Scanner {
    char buf[1000];
    char *p;

    Scanner() {
        p = buf;
    }

    string next() {
        p = buf;
        while (*p!='' && *p!= '\0') {
            p++;
        }
        string result(buf, p);
        p++;
        return result;
    }

    string nextLine() {
        p = buf;
        while (*p!= '\n' && *p!= '\0') {
            p++;
        }
        string result(buf, p);
        p++;
        return result;
    }

    int nextInt() {
        int v;
        sscanf(next().c_str(), "%d", &v);
        return v;
    }

    vector<int> nextIntArray() {
        p = buf;
        vector<int> result;
        while (*p!= '\0') {
            if (*p =='') {
                p++;
                continue;
            }
            int v;
            sscanf(p, "%d", &v);
            result.push_back(v);
            while (*p!='' && *p!= '\0') {
                p++;
            }
        }
        return result;
    }
};

int main() {
    Scanner sc;
    string S = sc.next();
    if (S.substr(0, 5) == "YAKI") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

// min returns the smaller of two integers
int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

// max returns the larger of two integers
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// 