#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

def digit(n):
  res=0
  while n>0:
    res+=1
    n/=10
  return res

def run():
  n=int(input())
  min=digit(n)
  i=1
  while i*i<=n:
    if n%i!=0:
      i+=1
      continue
    a=i
    b=n/i
    min=min(min,max(digit(a),digit(b)))
    i+=1
  print(min)

run()

