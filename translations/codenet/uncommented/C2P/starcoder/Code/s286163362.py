
#include <stdio.h>
#include <string.h>

def max(a,b):
  if(a > b):
    return a;
  return b;

def main():
  while(1):
    n,k = map(int,raw_input().split())
    if(n == 0 and k == 0):
      break;
    data = [0 for i in range(111111)]
    seq = [0 for i in range(222222)]
    for i in range(k):
      t = int(raw_input())
      data[t] += 1
    p = 0
    for i in range(1,n+1):
      if(data[i]):
	seq[p] += 1
      else:
	p += 2
    p += 1
    if(data[0]):
      ret = 0
      for i in range(p):
	ret = max(ret,seq[i]+seq[i+2]+1)
    else:
      ret = 0
      for i in range(p):
	ret = max(ret,seq[i])
    print ret

main()

