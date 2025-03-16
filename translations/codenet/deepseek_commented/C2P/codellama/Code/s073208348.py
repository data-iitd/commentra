#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

#define vcnt g.vcnt
#define ecnt g.ecnt
#define e g.e
#define id g.id

#define esort(a,b)((a).s<(b).s?-1:(a).s>(b).s?1:(a).g<(b).g?-1:(a).g>(b).g?1:0)

class G:
	def __init__(self):
		self.vcnt=0
		self.ecnt=0
		self.e=[]
		self.id=[]

def readgraph():
	#適宜変える
	n=int(input())
	rep(i,0,n-1):
		x,y,c=map(int,input().split())
		e.append((x,y,c))
		e.append((y,x,c))
	vcnt=n
	ecnt=2*n-2
	e.sort(key=esort)

	p=0
	rep(i,0,vcnt):
		while p<ecnt and e[p][0]<i:
			p+=1
		id.append(p)
	id.append(ecnt)

def tyokkeidfs(s):
	for i in range(id[s],id[s+1]):
		if tyokkeitemp[e[i][1]]==0:
			tyokkeitemp[e[i][1]]=tyokkeitemp[s]+e[i][2]
			tyokkeidfs(e[i][1])

def tyokkei():
	tyokkeitemp=[0]*(vcnt+10)
	tyokkeitemp[0]=1
	tyokkeidfs(0)
	M=0
	Mi=0
	rep(i,0,vcnt):
		if tyokkeitemp[i]>M:
			M=tyokkeitemp[i]
			Mi=i
	rep(i,0,vcnt):
		tyokkeitemp[i]=0
	tyokkeitemp[Mi]=1
	tyokkeidfs(Mi)
	rep(i,0,vcnt):
		M=max(M,tyokkeitemp[i])
	return M-1

g=G()
readgraph()
print(tyokkei())

