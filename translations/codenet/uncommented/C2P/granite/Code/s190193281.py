
#include<stdio.h>
#define N 1000000
#define Q 50000
int n,S[N],T[Q];

int binarySearch(int key):
  left = 0
  right = n
  while left < right:
    mid = (left+right)/2
    if S[mid] == key:
      return 1
    elif key < S[mid]:
      right = mid
    else:
      left = mid+1
  return 0

def main():
  i = 0
  j = 0
  q = 0
  c = 0
  
  n = int(input())
  for i in range(n):
    S[i] = int(input())
  
  q = int(input())
  for i in range(q):
    T[i] = int(input())
    if binarySearch(T[i]) == 1:
      c += 1
  
  print(c)
  
  return 0

