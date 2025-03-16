
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

class FastScanner {
public:
    string next() {
        string s;
        char c;
        while (true) {
            c = getchar();
            if (c == ' ' || c == '\n' || c == '\t') {
                if (s.size() > 0) {
                    break;
                }
            } else {
                s += c;
            }
        }
        return s;
    }

    int nextInt() {
        return atoi(next().c_str());
    }

    long nextLong() {
        return atol(next().c_str());
    }

    double nextDouble() {
        return atof(next().c_str());
    }

    string nextLine() {
        string s;
        char c;
        while (true) {
            c = getchar();
            if (c == '\n') {
                break;
            }
            s += c;
        }
        return s;
    }
};

int main() {
    FastScanner fsc;
    int A, B, C;
    A = fsc.nextInt();
    B = fsc.nextInt();
    C = fsc.nextInt();
    if (B - A == C - B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

