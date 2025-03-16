#include<stdio.h>

#define MAX 100005
#define N 100

class P:
  def __init__(self,name,t):
    self.name=name
    self.t=t

Q=[P(0,0) for i in range(MAX)]
head=tail=0

def Enqueue(x):
  if(MAX==tail): tail=0
  Q[tail]=x
  tail+=1

def Dequeue():
  if(head==MAX): head=0
  return Q[head]

def main():
  n,q=map(int,input().split())
  for i in range(n):
    a=P(*input().split())
    Enqueue(a)
  while(n!=0):
    a=Dequeue()
    if(a.t>q):
      a.t-=q
      T+=q
      Enqueue(a)
    else:
      T+=a.t
      print(a.name,T)
      n-=1

main()

