
#include <string.h>
#include<stdio.h>
def main():
	sum=0
	flag=0
	x=raw_input()
	while(x[0]!=0x30):
		for i in range(0,1002):
			if(x[i]==0):
				print sum
				break
			else:
				sum+=x[i]-0x30
		sum=0
		x=raw_input()

main()

