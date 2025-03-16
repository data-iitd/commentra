
#include<stdio.h>
#define N 4

class Pazz:
  def __init__(self):
    self.P=[[0 for i in range(N)] for j in range(N)]

Q=Pazz()
dx=[0,1,0,-1]
dy=[1,0,-1,0]

def Heu(Q):
  i,j
  hx,hy,sum=0
  for i in range(N):
    for j in range(N):
      if(Q.P[i][j]==0)continue
      hx=(Q.P[i][j]-1)%N-j
      hy=(Q.P[i][j]-1)/N-i
      if(hx<0)sum-=hx
      else sum+=hx
      if(hy<0)sum-=hy
      else sum+=hy
  return sum

def dfs (x,y,max,count,n):
  i,temp
  x0,y0,ans=-1,h
  h=Heu(Q)
  if(h==0)return count
  if((count+h) > max)return -1
  for i in range(4):
    x0=x+dx[i]
    y0=y+dy[i]
    if(((i == (n+2)%4 )and (n!=-1))or not((0<=x0 )and ( x0<N) and (0<=y0) and (y0<N)))continue
    temp=Q.P[y][x]
    Q.P[y][x]=Q.P[y0][x0]
    Q.P[y0][x0]=temp
    ans= dfs(x0,y0,max,count+1,i)
    if(ans!=-1)return ans
    temp=Q.P[y][x]
    Q.P[y][x]=Q.P[y0][x0]
    Q.P[y0][x0]=temp
  return -1

def main():
  i,j
  kx,ky,ans,a
  tP=Pazz()
  for i in range(N):
    for j in range(N):
      scanf("%d",&a)
      Q.P[i][j]=a
      if(a==0):
        kx=j
        ky=i
  tP=Q
  for i in range(1,46):
    Q=tP
    ans=dfs(kx,ky,i,0,-1)
    if(ans!=-1):
      printf("%d\n",ans)
      break
  return 0

main()

