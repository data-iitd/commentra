
#include<stdio.h>

#define M 100
#define whi 0
#define gra 1
#define bla 2

n = 0
T = [[0 for i in range(M)] for j in range(M)]
color = [0 for i in range(M)]
d = [0 for i in range(M)]
Q = [0 for i in range(M)]
head = 0
tail = 0

def enqueue(x):
  Q[tail] = x
  tail = (tail+1)%M

def dequeue():
  x = Q[head]
  head = (head+1)%M
  return x

def bfs(s):
  i,u,v

  for i in range(n):
    color[i] = whi
    d[i] = 1000000

  color[s] = gra
  d[s] = 0
  enqueue(s)

  while(head!= tail):
    u = dequeue()
    for v in range(n):
      if(T[u][v] == 1 and color[v] == whi):
	color[v] = gra
	d[v] = d[u]+1
	enqueue(v)
    color[u] = bla

def main():
  global n
  i,j,u,k,v

  n = int(input())

  for i in range(n):
    for j in range(n):
      T[i][j] = 0

  for i in range(n):
    u,k = map(int,input().split())
    u -= 1
    for j in range(k):
      v = int(input())
      v -= 1
      T[u][v] = 1

  bfs(0)

  for i in range(n):
    if(d[i] == 1000000): d[i] = -1
    print(i+1,d[i])

main()

