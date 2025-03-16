
#include <stdio.h>

def main():
	while(1):
		a,b,n=map(int,raw_input().split())
		if(a==-1 and b==-1 and n==-1):break
		a-=a/b*b
		sum=0
		for i in range(1,n+1):
			a*=10
			for j in range(9,-1,-1):
				if(b*j<=a):break
			a-=b*j
			sum+=j
		print sum

main()

