#include<stdio.h>
#define N 1000000
#define Q 50000
S = [0] * N
T = [0] * Q

def binarySearch(key):
  left = 0
  right = n
  while left < right:
    mid = (left+right)//2
    if S[mid] == key:
      return 1
    elif key < S[mid]:
      right = mid
    else:
      left = mid+1
  return 0

n = int(input())
for i in range(n):
  S[i] = int(input())

q = int(input())
for i in range(q):
  T[i] = int(input())

c = 0
for i in range(q):
  if binarySearch(T[i]) == 1:
    c += 1

print(c)

