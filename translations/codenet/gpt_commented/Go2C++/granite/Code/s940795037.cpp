
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

class Scanner {
private:
    char buf[1000];
    char *p;
    FILE *fp;

public:
    Scanner() {
        fp = stdin;
        p = buf;
    }

    string next() {
        while (*p =='') {
            p++;
        }
        char *start = p;
        while (*p!='' && *p!= '\0') {
            p++;
        }
        string result(start, p);
        if (*p =='') {
            p++;
        }
        return result;
    }

    string nextLine() {
        char *start = p;
        while (*p!= '\n' && *p!= '\0') {
            p++;
        }
        string result(start, p);
        if (*p == '\n') {
            p++;
        }
        return result;
    }

    int nextInt() {
        int v;
        sscanf(p, "%d", &v);
        while (*p!='' && *p!= '\0') {
            p++;
        }
        if (*p =='') {
            p++;
        }
        return v;
    }

    vector<int> nextIntArray() {
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
            if (*p =='') {
                p++;
            }
        }
        return result;
    }

    map<int, bool> nextMap() {
        map<int, bool> result;
        while (*p!= '\0') {
            if (*p =='') {
                p++;
                continue;
            }
            int v;
            sscanf(p, "%d", &v);
            result[v] = true;
            while (*p!='' && *p!= '\0') {
                p++;
            }
            if (*p =='') {
                p++;
            }
        }
        return result;
    }
};

int main() {
    Scanner sc;
    int n = sc.nextInt();
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int tmp = 1 / sc.nextInt();
        ans += tmp;
    }
    printf("%v\n", 1 / ans);
    return 0;
}

// END-OF-CODE