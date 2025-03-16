
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <stack>
#include <set>

using namespace std;

using ll = long long;
using ld = long double;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define rep4(i, m, n, p) for (int i = (m); i < (int)(n); i += (p))
#define rep_from(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define rep_from3(i, a, m, n) for (int i = (int)(a); i < (int)(m) && i < (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rrep3(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define rrep4(i, m, n, p) for (int i = (int)(n) - 1; i >= (int)(m); i -= (p))
#define foreach(v, c) for (auto&& v : c)

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template <class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T> inline T pow(T a, T b) {
  return a == 0 ? 0 : a * pow(a, b - 1);
}

template <class T> inline T powmod(T a, T b, T m = 1000000007) {
  if (b == 0) return 1;
  if (b % 2 == 1) return a * powmod(a, b - 1, m) % m;
  return powmod(a * a % m, b / 2, m);
}

template <class T> inline T gcd(T a, T b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}

template <class T> inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

template <class T> inline T binary_search(T ok, T ng, function<bool(T)> f) {
  while (abs(ok - ng) > 1) {
    T mid = (ok + ng) / 2;
    if (f(mid))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}

template <class T> inline T lower_bound(T vec[], T val, int N) {
  int L = 0, R = N - 1;
  while (L < R) {
    int mid = (L + R) / 2;
    if (vec[mid] >= val)
      R = mid;
    else
      L = mid + 1;
  }
  return L;
}

template <class T> inline T upper_bound(T vec[], T val, int N) {
  int L = 0, R = N - 1;
  while (L < R) {
    int mid = (L + R) / 2;
    if (vec[mid] > val)
      R = mid;
    else
      L = mid + 1;
  }
  return L;
}

template <class T> inline T max3(T a, T b, T c) {
  return max(a, max(b, c));
}

template <class T> inline T min3(T a, T b, T c) {
  return min(a, min(b, c));
}

template <class T> inline T max4(T a, T b, T c, T d) {
  return max(a, max(b, max(c, d)));
}

template <class T> inline T min4(T a, T b, T c, T d) {
  return min(a, min(b, min(c, d)));
}

template <class T> inline T max5(T a, T b, T c, T d, T e) {
  return max(a, max(b, max(c, max(d, e))));
}

template <class T> inline T min5(T a, T b, T c, T d, T e) {
  return min(a, min(b, min(c, min(d, e))));
}

template <class T> inline T max6(T a, T b, T c, T d, T e, T f) {
  return max(a, max(b, max(c, max(d, max(e, f)))));
}

template <class T> inline T min6(T a, T b, T c, T d, T e, T f) {
  return min(a, min(b, min(c, min(d, min(e, f)))));
}

template <class T> inline T max7(T a, T b, T c, T d, T e, T f, T g) {
  return max(a, max(b, max(c, max(d, max(e, max(f, g))))));
}

template <class T> inline T min7(T a, T b, T c, T d, T e, T f, T g) {
  return min(a, min(b, min(c, min(d, min(e, min(f, g))))));
}

template <class T> inline T max8(T a, T b, T c, T d, T e, T f, T g, T h) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, h)))))));
}

template <class T> inline T min8(T a, T b, T c, T d, T e, T f, T g, T h) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, h)))))));
}

template <class T> inline T max9(T a, T b, T c, T d, T e, T f, T g, T h, T i) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, i))))))));
}

template <class T> inline T min9(T a, T b, T c, T d, T e, T f, T g, T h, T i) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, i))))))));
}

template <class T> inline T max10(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, j)))))))));
}

template <class T> inline T min10(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, j)))))))));
}

template <class T> inline T max11(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, k))))))))));
}

template <class T> inline T min11(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, k))))))))));
}

template <class T> inline T max12(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, l)))))))))));
}

template <class T> inline T min12(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, l)))))))))));
}

template <class T> inline T max13(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, m))))))))))));
}

template <class T> inline T min13(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, m))))))))))));
}

template <class T> inline T max14(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, n)))))))))))));
}

template <class T> inline T min14(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, n)))))))))))));
}

template <class T> inline T max15(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, max(n, o))))))))))))));
}

template <class T> inline T min15(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, min(n, o))))))))))))));
}

template <class T> inline T max16(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, max(n, max(o, p)))))))))))))));
}

template <class T> inline T min16(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, min(n, min(o, p)))))))))))))));
}

template <class T> inline T max17(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p, T q) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, max(n, max(o, max(p, q))))))))))))))));
}

template <class T> inline T min17(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p, T q) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, min(n, min(o, min(p, q))))))))))))))));
}

template <class T> inline T max18(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p, T q, T r) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, max(n, max(o, max(p, max(q, r)))))))))))))))));
}

template <class T> inline T min18(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p, T q, T r) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, min(n, min(o, min(p, min(q, r)))))))))))))))));
}

template <class T> inline T max19(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p, T q, T r, T s) {
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, max(n, max(o, max(p, max(q, max(r, s))))))))))))))))));
}

template <class T> inline T min19(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p, T q, T r, T s) {
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, min(n, min(o, min(p, min(q, min(r, s))))))))))))))))));
}

template <class T> inline T max20(T a, T b, T c, T d, T e, T f, T g, T