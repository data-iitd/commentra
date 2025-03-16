// Preprocessor directives and header file inclusions
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <cstdio>

using namespace std;

// Constants and macro definitions
#define BIG 2000000007
#define VERYBIG 20000000000000007LL
#define MOD 1000000007
#define FOD  998244353
typedef uint64_t ull;
typedef int64_t sll;
#define N_MAX 1048576

#ifndef M_PI
// Define M_PI constant for math library
#define M_PI 3.14159265358979323846264338327950
#endif

// Data type and structure definitions
struct hwll {
    sll a;
    sll b;
};

struct hwllc {
    sll a;
    sll b;
    sll c;
};

struct hwreal {
    double a;
    double b;
};

// Variable declarations
sll n, m;
sll h, w;
sll k;
sll q;
sll va, vb, vc, vd, ve, vf;
ull ua, ub, uc, ud, ue, uf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
char ch, dh;
string s; // Assuming s is a string to hold input

// Helper function declarations
ull umin(ull x, ull y);
ull umax(ull x, ull y);
sll smin(sll x, sll y);
sll smax(sll x, sll y);
ull gcd(ull x, ull y);
ull bitpow(ull a, ull x, ull modulo);
ull divide(ull a, ull b, ull modulo);
ull udiff(ull a, ull b);
int bitcount(ull n);

// Function declarations
int32_t pullcomp(const void *left, const void *right);
int32_t prevcomp(const void *left, const void *right);
int32_t psllcomp(const void *left, const void *right);
int32_t pcharcomp(const void *left, const void *right);
int32_t pdoublecomp(const void *left, const void *right);
int32_t pstrcomp(const void *left, const void *right);
int32_t phwllABcomp(const void *left, const void *right);
int32_t phwllREVcomp(const void *left, const void *right);
int32_t ptriplecomp(const void *left, const void *right);
int32_t ptripleREVcomp(const void *left, const void *right);
int32_t ptripleCABcomp(const void *left, const void *right);
int32_t pquadcomp(const void *left, const void *right);
int32_t pfracomp(const void *left, const void *right);
bool isinrange(sll left, sll x, sll right);
bool isinrange_soft(sll left, sll x, sll right);
void sw(sll *l, sll *r);
ull ncr(sll n, sll r, ull m);

// Main function implementation
int32_t main(int argc, char *argv[]) {
    int32_t i, j;

    // Initialize variables
    n = 4;
    m = 0;

    // Read input values
    cin >> s;

    // Initialize arrays
    vector<sll> a(N_MAX, 0);
    vector<sll> b(N_MAX, 0);
    vector<sll> c(N_MAX, 0);

    // Read input values
    for (i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Read input values
    for (i = 0; i < m; i++) {
        cin >> c[i];
    }

    // Read input value
    cin >> q;

    // Call the solve function
    solve();

    // Terminate the program
    return 0;
}

// Main function implementation
int32_t solve() {
    sll i, j, ki, li;
    // Initialize variables
    sll result = 0;
    sll maybe = 0;
    sll sum = 0;
    sll item;
    sll *dpcell;

    result = 1;
    for (i = 0; i < n * 3; i++) {
        ull v;
        switch (s[i]) {
            case 'R':
                v = 0;
                break;
            case 'G':
                v = 1;
                break;
            case 'B':
                v = 2;
                break;
        }
        // Logic for result calculation
        // Assuming cnt and pcnt are defined and initialized somewhere
        if (cnt[(v + 1) % 3] && cnt[(v + 2) % 3]) {
            result *= pcnt;
            pcnt--;
            result %= FOD;
            cnt[(v + 1) % 3]--;
            cnt[(v + 2) % 3]--;
        } else {
            if ((cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]) {
                result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v];
                result %= FOD;
                pcnt++;
            }
            cnt[v]++;
        }
    }

    for (i = 1; i <= n; i++) {
        result = (result * i) % FOD;
    }

    cout << result << endl;

    return 0;

success:
    puts("Yes");
    return 0;

fail:
    puts("-1");
    return 1;
}

// Helper function implementations would go here

