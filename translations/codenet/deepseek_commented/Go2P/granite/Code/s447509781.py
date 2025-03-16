

import sys

def main():
  n = int(input())
  s = list(map(int,input().split()))
  u = [False]*n
  m,f = 0,0
  for c in range(1,n-1):
    f = 0
    for k in range(0,n-1-k*c,c):
      u[k*c] = True
      if u[n-1-k*c]: break
      f += s[n-1-k*c]+s[k*c]
      if m < f: m = f
    for k in range(0,n-1,c): u[k*c] = False
  print(m)

if __name__ == "__main__": main()

