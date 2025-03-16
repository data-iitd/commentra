
import sys

class Input:
  def __init__(self, stream):
    self.stream = stream
    self.buffer = ""
  def readline(self):
    while "\n" not in self.buffer:
      self.buffer += self.stream.readline()
    pos = self.buffer.find("\n")
    line = self.buffer[:pos]
    self.buffer = self.buffer[pos+1:]
    return line
  def readint(self):
    return int(self.readline())
  def readints(self):
    return [int(x) for x in self.readline().split()]

input = Input(sys.stdin)
n = input.readint()
s = input.readints()
u = [False]*n
m = 0
for c in range(1,n-1):
  f = 0
  for k in range(0,n-1-c*k):
    u[k*c] = True
    if u[n-1-k*c]: break
    f += s[n-1-k*c]+s[k*c]
    if m < f: m = f
  for k in range(0,n-1-c*k): u[k*c] = False
print(m)

