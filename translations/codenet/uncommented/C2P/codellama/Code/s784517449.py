#include <stdio.h>

A = [0] * 1000000
n = 0

# 二分探索
def binarySearch(key):
  left = 0
  right = n
  mid = 0
  while left < right:
    mid = (left + right) // 2
    if key == A[mid]:
      return 1 # keyを発見
    if key > A[mid]:
      left = mid + 1 # 後半を探索
    else:
      right = mid # 前半を探索
  return 0

def main():
  global n
  global A
  global q
  global k
  global sum
  n = int(input())
  for i in range(n):
    A[i] = int(input())
  q = int(input())
  for i in range(q):
    k = int(input())
    if binarySearch(k):
      sum += 1
  print(sum)

if __name__ == "__main__":
  main()

