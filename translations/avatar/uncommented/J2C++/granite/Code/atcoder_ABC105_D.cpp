
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) FOR(i, 0, (n)-1)
#define FOREACH(i, t) for (typeof(t.begin()) i = t.begin(); i!= t.end(); i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) ((int)(a).size())

#ifdef LOCAL
#define DEBUG(x) cout << #x << " = " << x << endl
#define DEBUG2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define DEBUG3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#else
#define DEBUG(x)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#endif

#define MAXN 100010
#define MOD 100000007
#define eps 1e-9
#define PI acos(-1.0)

inline void read(int &x) { scanf("%d", &x); }
inline void read(LL &x) { scanf("%I64d", &x); }
inline void read(double &x) { scanf("%lf", &x); }
inline void read(char *s) { scanf("%s", s); }

inline void write(int x) { printf("%d", x); }
inline void write(LL x) { printf("%I64d", x); }
inline void write(double x) { printf("%.9lf", x); }
inline void write(char x) { printf("%c", x); }
inline void write(char *x) { printf("%s", x); }

template<typename T>
inline T abs(T a) { return a < 0? -a : a; }

template<typename T>
inline T sqr(T a) { return a * a; }

template<typename T>
inline T gcd(T a, T b) { if (b == 0) return a; else return gcd(b, a % b); }

template<typename T>
inline T mod(T a, T b) { return (a % b + b) % b; }

template<typename T>
inline T addmod(T a, T b, T c) { return (T)mod((LL)a + b, (LL)c); }

template<typename T>
inline T mulmod(T a, T b, T c) { return (T)mod((LL)a * b, (LL)c); }

template<typename T>
inline T powmod(T a, T b, T c) {
    if (b == 0) return 1;
    T ret = powmod(a, b >> 1, c);
    ret = ret * ret % c;
    if (b & 1) ret = ret * a % c;
    return ret;
}

template<typename T>
inline T invmod(T a, T b) { return powmod(a, b - 2, b); }

template<typename T>
inline void maxe(T &a, T b) { if (a < b) a = b; }

template<typename T>
inline void mine(T &a, T b) { if (a > b) a = b; }

template<typename T>
inline void make_unique(vector<T> &v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), v.end());
}

inline void fileio_in_out() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
}

inline void fileio_txt() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

class InputReader {
public:
    InputReader(const string &file_name) {
        input_file = fopen(file_name.c_str(), "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    inline InputReader &operator >>(int &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor]!= '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }

    inline InputReader &operator >>(LL &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor]!= '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }

    inline InputReader &operator >>(string &s) {
        while (buffer[cursor] <='') {
            advance();
        }
        s = "";
        while (buffer[cursor] >'') {
            s += buffer[cursor++];
        }
        return *this;
    }

private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];

    inline void advance() {
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 100010;
const int MOD = 100000007;

int n, m;
int a[MAXN];
map<int, int> cnt;
LL ans;

int main() {
    fileio_txt();
    InputReader in("input.txt");
    in >> n >> m;
    REP(i, n) {
        in >> a[i];
    }
    int sum = 0;
    cnt[0] = 1;
    REP(i, n) {
        sum = (sum + a[i]) % m;
        ans += cnt[sum];
        cnt[sum]++;
    }
    cout << ans << endl;
    return 0;
}

