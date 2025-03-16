
n=int(input())
a=[[0]*(n-1) for i in range(n)]
for i in range(n):
	for j in range(n-1):
		a[i][j]=int(input())-1
e1=[0]*(n*n)
e2=[0]*(n*n)
d=[0]*(n*n)
b=[False]*(n*n)

def f(from):
	if(b[from]): return -1
	if(d[from]): return d[from]
	b[from]=True
	to=e1[from]
	max=0
	if(to!=0):
		now=f(to)
		if(now<0): return now
		if(now>max): max=now
	to=e2[from]
	if(to!=0):
		now=f(to)
		if(now<0): return now
		if(now>max): max=now
	b[from]=False
	return d[from]=max+1

ans=0
for i in range(n):
	from=p(i, a[i][0])
	now=f(from)
	if(now<0):
		ans=-1
		break
	if(now>ans): ans=now
print(ans)

