#include <stdio.h>

typedef struct {
  char s;
  int v;
} card;

card L[100000/2+2],R[100000/2+2];

def me(a,n,l,m,r):
  n1 = m-l
  n2=r-m

  for i in range(n1):
    L[i]=a[l +i]
  for i in range(n2):
    R[i]=a[m +i]
  L[n1].v=R[n2].v=2000000000
  i=0
  j=0
  for k in range(l,r):
    if L[i].v<=R[j].v:
      a[k]=L[i]
      i+=1
    else:
      a[k]=R[j]
      j+=1

def ms(a , n, l,r):
  m=0
  if l+1<r:
    m=(l+r)/2
    ms(a,n,l,m)
    ms(a,n,m,r)
    me(a,n,l,m,r)

def partiton(a,n,p,r):
  i=0
  j=0
  x=a[r]
  for j in range(p,r):
    if a[j].v<=x.v:
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
  if p<r:
    q=partiton(a,n,p,r)
    qs(a,n,p,q-1)
    qs(a,n,q+1,r)

n=0
i=0
v=0
a=[]
b=[]
s=""
stable=1

scanf("%d",&n)

for i in range(n):
  scanf("%s%d",s,&v)
  a.append(card(s[0],v))
  b.append(card(s[0],v))

ms(a,n,0,n)
qs(b,n,0,n-1)

for i in range(n):
  if a[i].s!=b[i].s:
    stable=0

if stable==1:
  print("Stable\n")
else:
  print("Not stable\n")
for i in range(n):
  print("%c %d\n"%(b[i].s,b[i].v))

