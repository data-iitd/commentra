#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

// 最大公約数
int gcd(int x, int y) {
  int tmp = 0;
  if (x < y){
    tmp = x;
    x = y;
    y = tmp;
  }
  while (y > 0) {
    int r = x % y;
    x = y;
    y = r;
  }
  return x;
}

// 最小公倍数
int lcm(int x, int y) {
  return x / gcd(x, y) * y;
}

// 階乗
long long kaijo(int k) {
    long long sum = 1;
    for (int i = 1; i <= k; ++i) {
        sum *= i;
        sum %= 1000000000 + 7;
    }
    return sum;
}

// for(int i = ; i < ; i++){}

int lmax(int s, int t) {
  return s > t ? s : t;
}

int lmin(int s, int t) {
  return s < t ? s : t;
}

// ここから開始

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long sum = 0;
  for (int b = 1; b <= n; b++) {
    int cnt = (n + 1) / b;
    int md = (n + 1) % b;
    sum += cnt * lmax(b - k, 0) + lmax(md - k, 0);
    if (k == 0) sum--;
  }
  printf("%lld\n", sum);
  return 0;
}
