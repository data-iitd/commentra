
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

def part(a,b,l,r):
  i = l - 1
  j = r
  x = b[r]
  while(1):
    while(b[++i] < x):
      pass
    while(i < --j and x < b[j]):
      pass
    if(i >= j): break
    t = a[i]
    a[i] = a[j]
    a[j] = t
    t = b[i]
    b[i] = b[j]
    b[j] = t
  t = a[i]
  a[i] = a[r]
  a[r] = t
  t = b[i]
  b[i] = b[r]
  b[r] = t
  return i

def quicksort(a,b,n):
  l = 0
  r = n - 1
  low = [0]
  high = [n - 1]
  sp = 1
  while(sp > 0):
    sp -= 1
    l = low[sp]
    r = high[sp]
    if(l >= r):
      pass
    else:
      v = part(a,b,l,r)
      if(v - l < r - v):
        low[sp] = v + 1
        high[sp] = r
        low.append(l)
        high.append(v - 1)
      else:
        low[sp] = l
        high[sp] = v - 1
        low.append(v + 1)
        high.append(r)

def main():
  n,m = map(int,raw_input().split())
  a = [0] * m
  b = [0] * m
  for i in range(m):
    a[i],b[i] = map(int,raw_input().split())
  quicksort(a,b,m)
  t = 0
  cnt = 0
  for i in range(m):
    if(t <= a[i]):
      t = b[i]
      cnt += 1
  print cnt
  return 0

if __name__ == "__main__":
  main()

