
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

class Scanner {
private:
    char buf[1000];
    char *p;
    FILE *r;

public:
    Scanner() {
        r = stdin;
        p = buf;
    }

    string next() {
        p = buf;
        while (*p =='') p++;
        char *start = p;
        while (*p!='' && *p!= '\0') p++;
        string result(start, p);
        p++;
        return result;
    }

    string nextLine() {
        p = buf;
        char *start = p;
        while (*p!= '\0') p++;
        string result(start, p);
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
            char *start = p;
            while (*p!='' && *p!= '\0') p++;
            int v;
            sscanf(string(start, p).c_str(), "%d", &v);
            result.push_back(v);
            p++;
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

