
#include<stdio.h> 
def main():
	a,b=map(int,raw_input().split())
	x=a+b
	w=0
	while(x):
		w+=1
		x/=10
	print w
main()

