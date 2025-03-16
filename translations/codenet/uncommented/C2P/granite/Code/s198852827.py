
#include<stdio.h>

#define ABS(x) (((x)<(0))?(-(x)):(x))

def main():
  N = int(input())
  t = 0
  x = 0
  y = 0
  for i in range(N):
    nt, nx, ny = map(int, input().split())
    tmp = nt - t - (ABS(nx - x) + ABS(ny - y))
    if tmp < 0 or tmp % 2:
      print("No")
      return 0
  print("Yes")

if __name__ == "__main__":
  main()

