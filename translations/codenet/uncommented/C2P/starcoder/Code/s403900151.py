
#include <stdio.h>

def main():
  while True:
    n,r = map(int,raw_input().split())
    if n == 0 and r == 0:
      break
    a = range(1,n+1)
    for i in range(r):
      p,c = map(int,raw_input().split())
      b = a[n-p-c+1:n-p+1]
      a[n-p-c+1:n-p+1] = b[::-1]
    print a[n-1]

if __name__ == "__main__":
  main()

