#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//#define double long double
const double PI=acos(-1.0);
int sig(double d) {
	return fabs(d) < 1e-8 ? 0 : d < 0 ? -1 : 1;
}

class Point:
	def __init__(self,x,y):
		self.x=x
		self.y=y
		self.k=0
	def set(self,x,y):
		self.x=x
		self.y=y
	def mod(self):
		return sqrt(self.x*self.x+self.y*self.y)
	def mod_pow(self):
		return self.x*self.x + self.y*self.y
	def output(self):
		print("x = %f, y = %f"%(self.x,self.y))
	def __lt__(self,p):
		return sig(self.x-p.x) != 0 ? self.x < p.x : sig(self.y-p.y) < 0

def dot(o,a,b):
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)

def dot(a,b):
	return a.x*b.x + a.y*b.y	#(a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y);

def cross(o,a,b):
	return (a.x - o.x)*(b.y - o.y)-(b.x - o.x)*(a.y - o.y)

def btw(x,a,b):
	return sig(dot(x,a,b))

def dis(a,b):
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))

def cos(o,a,b):
	return dot(o,a,b)/dis(o,a)/dis(o,b)

def jarvis(p,n,ch):
	d,i,o,s,l,t=0,0,0,0,0,0
	for i in range(n):
		if p[i] < p[d]:
			d=i
	l=s=ch[0]=d
	d=1
	do:
		o=l
		for i in range(n):
			if (t=sig(cross(p[o],p[l],p[i])))>0 or (t==0 and btw(p[l],p[o],p[i])<=0):
				l=i
		ch[d]=l
	while l!=s
	return d-1


def main():
	n=int(input())
	P=[Point(0,0) for i in range(n)]
	for i in range(n):
		xx,yy=map(int,input().split())
		P[i].set(xx,yy)
	if n==2:
		print("0.5")
		print("0.5")
	else:
		m=jarvis(P,n,ch)
		sum=0
#for i in range(m):
#	print(ch[i],end=" ")
#print()
		if m==2:
			ans[ch[0]]=0.5
			ans[ch[1]]=0.5
		else:
			for i in range(m):
				ang[ch[i]]=PI-acos(cos(P[ch[i]],P[ch[(i-1+m)%m]],P[ch[(i+1)%m]]))
			for i in range(n):
				ans[i]=ang[i]/2./PI
		for i in range(n):
			print("%.20f"%ans[i])
	return 0

