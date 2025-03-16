
# <START-OF-CODE>
import sys

class Input:
  def __init__(self, stream):
    self.stream = stream
    self.buffer = ""
  def NextLine(self):
    while True:
      if self.buffer!= "":
        line, self.buffer = self.buffer.split("\n",1)
        return line
      line = self.stream.readline()
      if line == "":
        return ""
      self.buffer = line
  def NextInt(self):
    return int(self.NextLine())
  def NextIntArray(self):
    return [int(x) for x in self.NextLine().split(" ")]

input = Input(sys.stdin)
n = input.NextInt()
s = input.NextIntArray()
u = [False]*n
m,f = 0,0
for c in range(1,n-1):
  f = 0
  for k in range(0,n-1-k*c):
    u[k*c] = True
    if u[n-1-k*c]: break
    f += s[n-1-k*c]+s[k*c]
    if m < f: m = f
  for k in range(0,n-1-k*c): u[k*c] = False
print(m)
# 