
import sys
import bufio

def main():
  input = Input(bufio.NewReaderSize(sys.stdin,1000000))
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
    for k in range(0,n-1//c): u[k*c] = False
  print(m)

class Input:
  def __init__(self,reader):
    self.reader = reader
  def NextLine(self):
    buffer = ""
    while True:
      line = self.reader.readline()
      buffer += line.decode("utf-8")
      if line[-1:] == b"\n": break
    return buffer
  def NextInt(self):
    return int(self.NextLine())
  def NextIntArray(self):
    s = self.NextLine().split(" ")
    a = [int(x) for x in s]
    return a

Translate the above Python code to Ruby and end with comment "