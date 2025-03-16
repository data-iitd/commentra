
import sys

LEN = 100005

class P:
  def __init__(self, name, t):
    self.name = name
    self.t = t

Q = [None] * LEN
head = 1
tail = 0
n = 0
elaps = 0

def enqueue(x):
  global tail
  Q[tail] = x
  tail = (tail + 1) % LEN

def dequeue():
  global head
  x = Q[head]
  head = (head + 1) % LEN
  return x

def min(a, b):
  return a if a < b else b

def main():
  global n, elaps
  n, q = map(int, input().split())
  for i in range(1, n + 1):
    name, t = input().split()
    enqueue(P(name, int(t)))
  while head!= tail:
    u = dequeue()
    c = min(q, u.t)
    u.t -= c
    elaps += c
    if u.t > 0:
      enqueue(u)
    else:
      print(u.name, elaps)

if __name__ == "__main__":
  main()

