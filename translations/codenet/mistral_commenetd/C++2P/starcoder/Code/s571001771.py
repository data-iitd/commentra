# Define necessary data types and constants
key=[0]*1005
cost=[0]*1005
dp=[[INF]*1005 for i in range(1<<12+5)]
# Define necessary functions
def min(a,b):
  if a<b:return a
  else:return b
# Read input
n,m=map(int,input().split())
# Read bulbs' information
for i in range(1,m+1):
  cost[i],b=map(int,input().split())
  for j in range(b):
    c=int(input())
    key[i]+=(1<<(c-1))
# Fill dynamic programming table
for i in range(1<<n):
  for j in range(m):
    dp[i][j+1]=min(dp[i][j],dp[i][j+1])
    dp[i|key[j+1]][j+1]=min(dp[i|key[j+1]][j+1],dp[i][j]+cost[j+1])
# Output result
if dp[(1<<n)-1][m]==INF:print(-1)
else:print(dp[(1<<n)-1][m])
# 