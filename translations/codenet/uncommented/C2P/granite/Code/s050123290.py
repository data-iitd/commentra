
#include<stdio.h>
#define N 1000 

int main(void){
	su=['0']*N
	susum=0
	j=0
	
	while(1):
		for j in range(N):
			su[j]=input()
			if(su[j]=='\n')break
			susum=susum+(ord(su[j])-ord('0'))
		if(su[0]=='0')break
		print susum
		susum=0
	return 0
}
