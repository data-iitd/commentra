#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))
def compare_int(a, b):
  return b - a # 大きい順

# 公約数
def gcd(a, b):
  if b == 0:
    return a
  else:
    return gcd(b, a % b)

# 最小公倍数 = a * b / 最大公約数
# 公倍数
def lcm(a, b):
  return a * b / gcd(a, b)


# min
def main():
  n = 0
  k = 0
  q = 0
  a = [0] * 100001
  point = [0] * 100001

  n, k, q = map(int, input().split())


  /*
  # 初期化
  for i in range(n):
    point[i] = k
  */
  /*
  if q < k:
    for i in range(n):
      print("Yes")
      return 0
    }*/
  #  一人ずつはしない。問題ずつそれぞれのポイントを考える
  for i in range(q):
    a[i] = int(input())
    point[a[i] - 1] += 1
    /*
    for j in range(n):
      if a[i] != (j + 1) and point[j] < k:
	point[j] += 1
      #      printf("i = %ld  point = %lld\n", i, point[j]);
    */
  }

  # 求め方を変えた
  for i in range(n):
    if k - (q - point[i]) > 0:
      print("Yes")
    else:
      print("No")

  return 0