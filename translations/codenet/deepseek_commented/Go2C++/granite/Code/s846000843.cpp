
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Io {
    char buffer[1000000];
    char *p;

    Io() {
        p = buffer;
    }

    ~Io() {
        fflush(stdout);
    }

    char nextChar() {
        if (p >= buffer + sizeof(buffer) - 1) {
            fread(buffer, 1, sizeof(buffer), stdin);
            p = buffer;
        }
        return *(p++);
    }

    int nextInt() {
        int x = 0;
        bool sign = false;
        while (true) {
            char ch = nextChar();
            if (ch =='' || ch == '\n') continue;
            if (ch == '-') sign = true;
            else if (ch >= '0' && ch <= '9') x = x * 10 + ch - '0';
            else break;
        }
        return sign? -x : x;
    }
};

int main() {
    Io io;
    int n = io.nextInt();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = io.nextInt();
    }
    vector<int> cumsum(n + 1);
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }
    int ans = 2020202020;
    for (int i = 1; i < n - 1; i++) {
        ans = min(ans, abs(cumsum[n] - 2 * cumsum[i]));
    }
    printf("%d\n", ans);
    return 0;
}

// 