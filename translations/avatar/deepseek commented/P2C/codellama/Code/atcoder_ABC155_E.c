
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>

#define INPUT_BUFFER_SIZE 1024
#define INPUT_BUFFER_TYPE char

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(a) (((a) < 0) ? -(a) : (a))
#define SGN(a) (((a) < 0) ? -1 : ((a) > 0))
#define CONTAINS(s, e) (strchr(s, e) != NULL)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define FOREACH(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(a) (a).begin(), (a).end()
#define ZERO(a) memset((a), 0, sizeof(a))
#define MEM(a, b) memset((a), (b), sizeof(a))
#define CPY(a, b) memcpy((a), (b), sizeof(a))
#define REP(i, n) FOR(i, 0, n)
#define REPP(i, a, n) FOR(i, a, n + 1)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define SQ(a) ((a)*(a))

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> vs;

const int INF = INT_MAX;
const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

struct io {
    char ibuf[INPUT_BUFFER_SIZE];
    char obuf[INPUT_BUFFER_SIZE];
    char *_i = ibuf, *_o = obuf;
    int fd;

    io() {
        fd = 0;
        setvbuf(stdin, ibuf, _IOFBF, INPUT_BUFFER_SIZE);
        setvbuf(stdout, obuf, _IOFBF, INPUT_BUFFER_SIZE);
    }

    io(int _fd) {
        fd = _fd;
        setvbuf(stdin, ibuf, _IOFBF, INPUT_BUFFER_SIZE);
        setvbuf(stdout, obuf, _IOFBF, INPUT_BUFFER_SIZE);
    }

    ~io() {
        fflush(stdout);
    }

    inline char read() {
        if (_i == ibuf + INPUT_BUFFER_SIZE) {
            _i = ibuf;
            fread(ibuf, 1, INPUT_BUFFER_SIZE, stdin);
        }
        return *_i++;
    }

    inline void write(char c) {
        if (_o == obuf + INPUT_BUFFER_SIZE) {
            fwrite(obuf, 1, INPUT_BUFFER_SIZE, stdout);
            _o = obuf;
        }
        *_o++ = c;
    }

    inline int32_t readInt() {
        int32_t x = 0;
        char c = read();
        while (c < '0') c = read();
        while (c >= '0') {
            x = (x << 1) + (x << 3) + c - '0';
            c = read();
        }
        return x;
    }

    inline int64_t readLong() {
        int64_t x = 0;
        char c = read();
        while (c < '0') c = read();
        while (c >= '0') {
            x = (x << 1) + (x << 3) + c - '0';
            c = read();
        }
        return x;
    }

    inline double readDouble() {
        double x = 0, f = 1;
        char c = read();
        while (c < '0' || c > '9') {
            if (c == '-') f = -1;
            c = read();
        }
        while (c >= '0' && c <= '9') {
            x = (x << 1) + (x << 3) + c - '0';
            c = read();
        }
        if (c == '.') {
            while (c >= '0' && c <= '9') {
                x += (c - '0') * (f /= 10);
                c = read();
            }
        }
        return x * f;
    }

    inline void readStr(char *str) {
        char c = read();
        while (c < '0') c = read();
        while (c >= '0') {
            *str++ = c;
            c = read();
        }
        *str = 0;
    }

    inline void writeInt(int x) {
        char buf[11];
        buf[10] = '\0';
        int i = 9;
        while (x) {
            buf[i--] = x % 10 + '0';
            x /= 10;
        }
        while (buf[i] != '\0') {
            write(buf[i--]);
        }
    }

    inline void writeLong(int64_t x) {
        char buf[21];
        buf[20] = '\0';
        int i = 19;
        while (x) {
            buf[i--] = x % 10 + '0';
            x /= 10;
        }
        while (buf[i] != '\0') {
            write(buf[i--]);
        }
    }

    inline void writeDouble(double x) {
        if (x < 0) {
            write('-');
            x = -x;
        }
        long long int part = (long long int)x;
        writeInt(part);
        write('.');
        int start = 1;
        while (x - part >= 1e-6) {
            x = (x - part) * 10;
            part = (long long int)x;
            if (start) {
                while (part >= 10) {
                    part /= 10;
                }
                start = 0;
            }
            writeInt(part);
        }
    }

    inline void writeStr(const char *str) {
        while (*str) {
            write(*str++);
        }
    }

    inline void writeChars(const char *chars) {
        while (*chars) {
            write(*chars++);
        }
    }

    inline void flush() {
        fwrite(obuf, 1, _o - obuf, stdout);
        _o = obuf;
    }
};

static io io_;
#define cin io_
#define cout io_

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = cin.readInt();
    int m = cin.readInt();
    int k = cin.readInt();
    int a[n];
    int b[m];
    int c[k];
    REP(i, n) {
        a[i] = cin.readInt();
    }
    REP(i, m) {
        b[i] = cin.readInt();
    }
    REP(i, k) {
        c[i] = cin.readInt();
    }
    int dp[n + 1][m + 1];
    ZERO(dp);
    REP(i, n + 1) {
        dp[i][0] = i;
    }
    REP(i, m + 1) {
        dp[0][i] = i;
    }
    REP(i, n) {
        REP(j, m) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j];
            } else {
                dp[i + 1][j + 1] = MIN(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    int ans = INF;
    REP(i, k) {
        ans = MIN(ans, dp[n][m] - dp[n - c[i]][m]);
    }
    cout.writeInt(ans);
    return 0;
}

