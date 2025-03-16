
ans,mx,sum,mn=1e8,1,1,1e8
cnt=1
h=int(input())
while(h!=1):
	if(h%2!=0): h-=1
	h/=2
	cnt*=2
	ans+=cnt
print(ans+1)

