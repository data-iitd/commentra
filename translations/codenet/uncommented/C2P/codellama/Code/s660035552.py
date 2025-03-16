#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

low = [0] * 200000
high = [0] * 200000
a = [0] * 200000

def part(a,b,l,r):
  i = l - 1
  j = r
  x = b[r]

  while(1):
    while(b[i+1] < x):
      i += 1
    while(i < j and x < b[j]):
      j -= 1

    if(i >= j):
      break

    a[i], a[j] = a[j], a[i]
    b[i], b[j] = b[j], b[i]

  a[i], a[r] = a[r], a[i]
  b[i], b[r] = b[r], b[i]
  return i

def quicksort(a,b,n):
  l,r,v = 0,0,0
  sp = 1

  low[0] = 0
  high[0] = n - 1

  while(sp > 0):
    sp -= 1
    l = low[sp]
    r = high[sp]

    if(l >= r):
      continue

    v = part(a,b,l,r)

    if(v - l < r - v):
      low[sp] = v + 1
      high[sp] = r
      low[sp+1] = l
      high[sp+1] = v - 1
    else:
      low[sp] = l
      high[sp] = v - 1
      low[sp+1] = v + 1
      high[sp+1] = r

def main():
  n,m = 0,0
  i = 0
  a = [0] * 100006
  b = [0] * 100006
  cnt = 0
  t = 0

  scanf("%d %d", &n, &m)

  for i in range(m):
    scanf("%d %d", &a[i], &b[i])

  quicksort(a,b,m)

  t = 0
  for i in range(m):
    if(t <= a[i]):
      t = b[i]
      cnt += 1

  printf("%d\n", cnt)

  return 0

