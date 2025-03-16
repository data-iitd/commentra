
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <cmath>
#include <bitset>
#include <limits>
#include <numeric>
#include <complex>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define rrep3(i, m, n) for (int i = (int)(n) - 1; i >= (m); i--)
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define mset(arr, val) memset(arr, val, sizeof(arr))
#define cons(a, b) make_pair(a, b)
#define car first
#define cdr second

#define endl '\n'
#define INF  0x7f7f7f7f7f7f7f7f
#define INFi 0x7f7f7f7f

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using plll = pair<ll, pll>;

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline T input() {
  T r = 0;
  char c = getchar();
  while (c > '9' || c < '0') {
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    r = r * 10 + c - '0';
    c = getchar();
  }
  return r;
}

template <class T>
inline void print(T n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n > 9) {
    print(n / 10);
  }
  putchar(n % 10 + '0');
}

template <class T>
inline void print_list(T l) {
  for (auto it = l.begin(); it != l.end(); it++) {
    if (it != l.begin()) {
      putchar(' ');
    }
    print(*it);
  }
}

template <class T>
inline void print_matrix(T A, int H, int W) {
  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      print(A[h][w]);
      if (w != W - 1) {
        putchar(' ');
      }
    }
    putchar('\n');
  }
}

template <class T>
inline void print_vector(T A, int N) {
  for (int n = 0; n < N; n++) {
    print(A[n]);
    if (n != N - 1) {
      putchar(' ');
    }
  }
}

template <class T>
inline T read() {
  T r = 0;
  char c = getchar();
  while (c > '9' || c < '0') {
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    r = r * 10 + c - '0';
    c = getchar();
  }
  return r;
}

template <class T>
inline void read(T &n) {
  n = read<T>();
}

template <class T, class U>
inline void read(T &n, U &m) {
  n = read<T>();
  m = read<U>();
}

template <class T, class U, class V>
inline void read(T &n, U &m, V &v) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
}

template <class T, class U, class V, class W>
inline void read(T &n, U &m, V &v, W &w) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
}

template <class T, class U, class V, class W, class X>
inline void read(T &n, U &m, V &v, W &w, X &x) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
}

template <class T, class U, class V, class W, class X, class Y>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
}

template <class T, class U, class V, class W, class X, class Y, class Z>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B, class C>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b,
                 C &c) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
  c = read<C>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B, class C, class D>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b, C &c,
                 D &d) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
  c = read<C>();
  d = read<D>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B, class C, class D, class E>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b, C &c,
                 D &d, E &e) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
  c = read<C>();
  d = read<D>();
  e = read<E>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B, class C, class D, class E, class F>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b, C &c,
                 D &d, E &e, F &f) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
  c = read<C>();
  d = read<D>();
  e = read<E>();
  f = read<F>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B, class C, class D, class E, class F, class G>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b, C &c,
                 D &d, E &e, F &f, G &g) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
  c = read<C>();
  d = read<D>();
  e = read<E>();
  f = read<F>();
  g = read<G>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B, class C, class D, class E, class F, class G,
          class H>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b, C &c,
                 D &d, E &e, F &f, G &g, H &h) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
  c = read<C>();
  d = read<D>();
  e = read<E>();
  f = read<F>();
  g = read<G>();
  h = read<H>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B, class C, class D, class E, class F, class G,
          class H, class I>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b, C &c,
                 D &d, E &e, F &f, G &g, H &h, I &i) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
  c = read<C>();
  d = read<D>();
  e = read<E>();
  f = read<F>();
  g = read<G>();
  h = read<H>();
  i = read<I>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B, class C, class D, class E, class F, class G,
          class H, class I, class J>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b, C &c,
                 D &d, E &e, F &f, G &g, H &h, I &i, J &j) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
  c = read<C>();
  d = read<D>();
  e = read<E>();
  f = read<F>();
  g = read<G>();
  h = read<H>();
  i = read<I>();
  j = read<J>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B, class C, class D, class E, class F, class G,
          class H, class I, class J, class K>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b, C &c,
                 D &d, E &e, F &f, G &g, H &h, I &i, J &j, K &k) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
  c = read<C>();
  d = read<D>();
  e = read<E>();
  f = read<F>();
  g = read<G>();
  h = read<H>();
  i = read<I>();
  j = read<J>();
  k = read<K>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B, class C, class D, class E, class F, class G,
          class H, class I, class J, class K, class L>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b, C &c,
                 D &d, E &e, F &f, G &g, H &h, I &i, J &j, K &k, L &l) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
  c = read<C>();
  d = read<D>();
  e = read<E>();
  f = read<F>();
  g = read<G>();
  h = read<H>();
  i = read<I>();
  j = read<J>();
  k = read<K>();
  l = read<L>();
}

template <class T, class U, class V, class W, class X, class Y, class Z,
          class A, class B, class C, class D, class E, class F, class G,
          class H, class I, class J, class K, class L, class M>
inline void read(T &n, U &m, V &v, W &w, X &x, Y &y, Z &z, A &a, B &b, C &c,
                 D &d, E &e, F &f, G &g, H &h, I &i, J &j, K &k, L &l, M &m) {
  n = read<T>();
  m = read<U>();
  v = read<V>();
  w = read<W>();
  x = read<X>();
  y = read<Y>();
  z = read<Z>();
  a = read<A>();
  b = read<B>();
  c = read<C>();
  d = read<D>();
  e = read<E>();
  f = read<