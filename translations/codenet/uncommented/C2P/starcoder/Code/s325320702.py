
l,r,d=map(int,input().split())
print(sum(i%d==0 for i in range(l,r+1)))

