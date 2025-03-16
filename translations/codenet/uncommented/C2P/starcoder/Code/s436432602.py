
#include<stdio.h>
#include<stdlib.h>

def run():
  n,k=map(int,raw_input().split())
  a=map(int,raw_input().split())
  dp=[0]*(k+1)
  for i in range(1,k+1):
    win=0
    for j in range(n):
      if a[j]<=i and dp[i-a[j]]==0:
	win=1
    dp[i]=win
  print "First" if dp[k] else "Second"

if __name__=="__main__":
  run()

