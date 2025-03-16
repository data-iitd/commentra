#include <stdio.h>

int main():
  n = int(input())
  fd = [0] * 6
  height = float(input())
  i = 0
  j = 0

  while n > 0:
    if height >= 185.0:
      fd[5] += 1
    elif height >= 180.0:
      fd[4] += 1
    elif height >= 175.0:
      fd[3] += 1
    elif height >= 170.0:
      fd[2] += 1
    elif height >= 165.0:
      fd[1] += 1
    else:
      fd[0] += 1
    n -= 1
    height = float(input())

  for i in range(6):
    print(i + 1, end = ':')
    for j in range(fd[i]):
      print('*', end = '')
    print()

  return 0

