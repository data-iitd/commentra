
#include <string.h>
#include<stdio.h>
def main():
	sum=0
	flag=0
	x=raw_input()
	while(x[0]!='0'):
		for i in range(0,len(x)):
			sum+=ord(x[i])-ord('0')
		print sum
		sum=0
		x=raw_input()

main()

