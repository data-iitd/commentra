#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <cstdio>

using namespace std;

#define MOD 1000000007
#define INF_INT 2147483647
#define INF_LL 9223372036854775807
#define INF_DOUBLE 1e18
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795

#define int long long

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define rep_se(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define rep_bi(i, a, b) for(int i = (int)(a); i >= (int)(b); --i)

#define readString(str) getline(cin, str)
#define printString(str) cout << str << endl
#define printLine() cout << endl
#define printInt(n) cout << n << endl
#define printInts(A) for(int i : A) cout << i << " "
#define printIntsLine(A) for(int i : A) cout << i << endl
#define printIntsSpace(A) for(int i : A) cout << i << " "

#define readInt() cin >> n
#define readInts(A) for(int &i : A) cin >> i
#define readInts1(A) for(int &i : A) cin >> i
#define readInt2() cin >> n >> m
#define readInt3() cin >> n >> m >> k
#define readInt4() cin >> n >> m >> k >> l

#define readLL() cin >> n
#define readLLs(A) for(int64_t &i : A) cin >> i
#define readLLs1(A) for(int64_t &i : A) cin >> i
#define readLL2() cin >> n >> m
#define readLL3() cin >> n >> m >> k
#define readLL4() cin >> n >> m >> k >> l

#define readFloat() cin >> n
#define readFloats(A) for(double &i : A) cin >> i
#define readFloats1(A) for(double &i : A) cin >> i
#define readFloat2() cin >> n >> m
#define readFloat3() cin >> n >> m >> k
#define readFloat4() cin >> n >> m >> k >> l

#define readRuneSlice() string str; getline(cin, str); vector<char> v(str.begin(), str.end())
#define printRuneSlice(v) for(char c : v) cout << c << " "
#define printRuneSliceLine(v) for(char c : v) cout << c << endl

#define readIntSlice(n) vector<int> A(n); for(int &i : A) cin >> i
#define readInt64Slice(n) vector<int64_t> A(n); for(int64_t &i : A) cin >> i
#define readFloat64Slice(n) vector<double> A(n); for(double &i : A) cin >> i

#define ZeroPaddingRuneSlice(n, digitsNum) string zeros = string(max(0, digitsNum - to_string(n).length()), '0'); return zeros + to_string(n)
#define Strtoi(s) stoi(s)

#define PrintIntsLine(A) for(int i : A) cout << i << " "
#define PrintInts64Line(A) for(int64_t i : A) cout << i << " "
#define PrintFloat64Line(A) for(double i : A) cout << i << " "

#define PrintfDebug(format, ...) fprintf(stderr, format, __VA_ARGS__)
#define PrintfBufStdout(format, ...) fprintf(stdout, format, __VA_ARGS__)

