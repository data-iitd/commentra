
l,r,d=map(int,input().split())
print(r-l+1-((l-1)%d+1+(r-1)%d+1-2*(l-1)//d-2*(r-1)//d))

