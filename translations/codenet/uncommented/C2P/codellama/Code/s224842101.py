#include <stdio.h>

def main():
  count = [0, 0, 0, 0]
  for i in range(4):
    count[i] = 0
  for i in range(3):
    a, b = input().split()
    count[int(a)-1] += 1
    count[int(b)-1] += 1
  s = 1
  for i in range(4):
    s *= count[i]
  if s == 4:
    print("YES")
  else:
    print("NO")

