#include<stdio.h>
#include<string.h>

#define LEN 100005

class P:
  def __init__(self, name, t):
    self.name = name
    self.t = t

Q = [P("", 0) for i in range(LEN)]
head, tail, n = 0, 1, 0

def enqueue(x):
  Q[tail] = x
  tail = (tail + 1) % LEN

def dequeue():
  x = Q[head]
  head = (head + 1) % LEN
  return x

def min(a, b):
  return a if a < b else b

def main():
  elaps = 0
  c = 0
  i = 0
  q = 0
  u = P("", 0)

  scanf("%d %d", &n, &q)

  for i in range(1, n + 1):
    scanf("%s", Q[i].name)
    scanf("%d", &Q[i].t)

  head = 1
  tail = n + 1

  while head != tail:
    u = dequeue()
    c = min(q, u.t)
    u.t -= c
    elaps += c
    if u.t > 0:
      enqueue(u)
    else:
      printf("%s %d\n", u.name, elaps)

  return 0



