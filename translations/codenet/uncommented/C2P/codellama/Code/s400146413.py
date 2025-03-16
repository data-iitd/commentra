#include<stdio.h>

def linearsearch(S, n, key):
  i = 0
  count = 0
  while S[i] != key:
    i += 1
    if i >= n:
      count = 1
      return count
  return count

def main():
  i, j, n, q, S, T = 0, 0, 0, 0, [], []
  count = 0
  key = 0

  n = int(input())
  for i in range(n):
    S.append(int(input()))

  q = int(input())
  for j in range(q):
    T.append(int(input()))

  for j in range(q):
    key = T[j]
    if linearsearch(S, n, key) == 0:
      count += 1

  print(count)

  return 0

