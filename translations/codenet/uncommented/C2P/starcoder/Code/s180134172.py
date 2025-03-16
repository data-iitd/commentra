n,k=map(int,input().split())
p=list(map(int,input().split()))
for i in range(n):
    for j in range(i+1,n):
        if p[i]>p[j]:
            p[i],p[j]=p[j],p[i]
print(sum(p[:k]))

