#include<stdio.h>

while(1):
	a,b,c,d,e,f=map(int,input().split())
	if(a==-1 and b==-1 and c==-1 and d==-1 and e==-1 and f==-1):
		break
	y=(c*d-f*a)/(b*d-e*a)
	x=(c*e-f*b)/(a*e-d*b)
	if(y<=0 and y>-0.0005):
		y=0
	if(x<=0 and x>-0.0005):
		x=0
	print("%.3f %.3f"%(x,y))

