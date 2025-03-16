

import sys

class Main:
 def __init__(self):
 self.count = 0
 self.seen = []
 self.path = 0
 self.cycle = 1
 self.graph = []

 def dfs(self, child, par):
 if self.seen[child] == True:
 return self.cycle
 self.seen[child] = True
 for i in self.graph[child]:
 if i!= par:
 self.count += 1
 if self.dfs(i, child) == self.cycle:
 return self.cycle
 return self.path

 def main(self):
 m, n = map(int, input().split())
 self.graph = [[] for _ in range(m + 1)]
 self.seen = [False] * (m + 1)
 for _ in range(n):
 x, y = map(int, input().split())
 self.graph[x].append(y)
 self.graph[y].append(x)
 toremove = 0
 for i in range(1, m + 1):
 if not self.seen[i]:
 self.count = 0
 if self.dfs(i, 0) == self.cycle:
 if self.count % 2 == 1:
 toremove += 1
 if (m - toremove) % 2 == 1:
 toremove += 1
 print(toremove)

