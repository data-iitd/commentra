
#include <stdio.h>

int A[1000000], n;

/* 二分探索 */
int binarySearch(int key):
  left = 0
  right = n
  while left < right:
    mid = (left + right) / 2
    if key == A[mid]:
      return 1 # keyを発見
    elif key > A[mid]:
      left = mid + 1 # 後半を探索
    else:
      right = mid # 前半を探索
  return 0

def main():
  i, q, k, sum = 0, 0, 0, 0
  n = int(input())
  for i in range(n):
    A[i] = int(input())
  q = int(input())
  for i in range(q):
    k = int(input())
    if binarySearch(k):
      sum += 1
  print(sum)
  return 0

