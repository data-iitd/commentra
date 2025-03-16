
#include <stdio.h>

// 最小公倍数
// Computes the greatest common divisor of two numbers x and y
int gcd(int x, int y) {
  int tmp = 0;
  if (x < y){
    tmp=x;
    x=y;
    y=tmp;
  }
  while (y > 0) {
    int r = x % y;
    x = y;
    y = r;
  }
  return x;
}

// 最大公倍数
// Computes the least common multiple of two numbers x and y
int lcm(int x, int y) {
  return x / gcd(x, y) * y;
}

// 階乗
// Computes the factorial of a number k modulo 10^9 + 7
int kaijo(int k) {
  int sum = 1;
  for (int i = 1; i <= k; ++i) {
    sum *= i;
    sum %= 1000000000 + 7;
  }
  return sum;
}

// for(int i = ; i < ; i++){}

// Utility functions to find the maximum and minimum of two numbers
int lmax(int s, int t) {
  if (s > t) {
    return s;
  } else {
    return t;
  }
}

int lmin(int s, int t) {
  if (s < t) {
    return s;
  } else {
    return t;
  }
}

// ここから開始

int main() {
  // Read two integers n and k
  int n, k;
  scanf("%d %d", &n, &k);
  int sum = 0;

  // Iterate over possible values of b
  for (int b = 1; b <= n; b++) {
    // Calculate the count and remainder
    int cnt = (n + 1) / b;
    int md = (n + 1) % b;

    // Update the sum based on the conditions involving k
    sum += cnt * max((b - k), 0) + max((md - k), 0);

    // Adjust the sum if k is 0
    if (k == 0) sum--;
  }

  // Print the computed sum
  printf("%d\n", sum);
  return 0;
}


Translate the above C code to Python and end with comment "