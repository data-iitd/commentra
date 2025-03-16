#include<stdio.h>
#include<string.h>
int main():
  n = int(input())
  while n:
    s = input()
    c = s.find("Hoshino")
    while c != -1:
      s = s[:c+6] + "a" + s[c+7:]
      c = s.find("Hoshino",c+1)
    print(s)
    n -= 1
  return 0
