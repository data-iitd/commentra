
#include <stdio.h>

class card:
  def __init__(self,s,v):
    self.s=s
    self.v=v

def me(a,n,l,m,r):
  n1 = m-l
  n2=r-m
  L=[card(0,0) for i in range(n1)]
  R=[card(0,0) for i in range(n2)]
  for i in range(n1):
    L[i]=a[l +i]
  for i in range(n2):
    R[i]=a[m +i]
  L[n1].v=R[n2].v=2000000000
  i=0
  j=0
  for k in range(l,r):
    if(L[i].v<=R[j].v):
      a[k]=L[i]
      i+=1
    else:
      a[k]=R[j]
      j+=1

def ms(a, n, l,r):
  m=(l+r)/2
  if(l+1<r):
    ms(a,n,l,m)
    ms(a,n,m,r)
    me(a,n,l,m,r)

def partiton(a,n,p,r):
  i=p-1
  x=a[r]
  for j in range(p,r):
    if(a[j].v<=x.v):
      i+=1
      t=a[i]
      a[i]=a[j]
      a[j]=t
  t=a[i+1]
  a[i+1]=a[r]
  a[r]=t
  return i+1

def qs(a,n,p,r):
  q=0
  if(p<r):
    q=partiton(a,n,p,r)
    qs(a,n,p,q-1)
    qs(a,n,q+1,r)

def main():
  n,i,v
  a=[card(0,0) for i in range(200000)]
  b=[card(0,0) for i in range(200000)]
  s=[0 for i in range(10)]
  stable=1

  n=int(input())

  for i in range(n):
    s,v=input().split()
    a[i].s=b[i].s=s[0]
    a[i].v=b[i].v=int(v)

  ms(a,n,0,n)
  qs(b,n,0,n-1)

  for i in range(n):
    if(a[i].s!=b[i].s):
      stable=0
  if(stable==1):
    print("Stable")
  else:
    print("Not stable")
  for i in range(n):
    print(b[i].s,b[i].v)

  return 0

