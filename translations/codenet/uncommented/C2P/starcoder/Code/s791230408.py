
#include <stdio.h>

def main():
	j=int(input())
	for i in range(j):
		a,b,c=map(int,input().split())
		max=a
		k=0
		if(max<=b):
			max=b
			k=1
		if(max<=c):
			max=c
			k=2
		max=max*max
		a=a*a
		b=b*b
		c=c*c
		if(k==0 and max==b+c):
			print("YES")
		elif(k==1 and max==a+c):
			print("YES")
		elif(k==2 and max==a+b):
			print("YES")
		else:
			print("NO")

main()

