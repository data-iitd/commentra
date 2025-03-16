#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
using vi = vector<int>;
using vi2 = vector<vi>;

def pow2(a):
  ret = 1
  for i in range(a):
    ret *= 2
  return ret

def count(hw, a, b):
  sum = 0
  for i in range(hw.size()):
    for j in range(hw[0].size()):
      if a >> i & 1 and b >> j & 1 and hw[i][j] == 1:
        sum += 1
  return sum

def main():
  h, w, k = map(int, input().split())
  hw = [vi(w, 0) for i in range(h)]
  for i in range(h):
    for j in range(w):
      c = input()
      if c == '#':
        hw[i][j] = 1
  sum = 0
  for i in range(pow2(h)):
    for j in range(pow2(w)):
      if count(hw, i, j) == k:
        sum += 1
  print(sum)

