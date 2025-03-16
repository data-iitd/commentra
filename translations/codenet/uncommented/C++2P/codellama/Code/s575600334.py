#include <iostream>
#include <cstdio>

using namespace std;

def binPrint(x, bits):
  for i in range(bits-1, -1, -1):
    print((x&(1<<i))>>i, end='')
  print()

a, b = map(int, input().split())

binPrint(a&b, 32)
binPrint(a|b, 32)
binPrint(a^b, 32)

# 