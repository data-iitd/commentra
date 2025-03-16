
n,k=map(int,input().split())
n+=1
z=0
if n%k:z=k-n%k
print(n+z)

