#include<stdio.h>

def isPrime(n):
	if n==1:
		return 0
	for i in range(2,n):
		if n%i==0:
			return 0
	return 1

def main():
	MAX_V=999999
	prime=[1]*(MAX_V+1)
	for i in range(2,MAX_V):
		if prime[i]==1:
			for k in range(2*i,MAX_V+1,i):
				prime[k]=0
	prime[0]=0
	prime[1]=0
	count=0
	while True:
		count+=1
		n=int(input())
		if n==0:
			break
		cnt=0
		for i in range(n,0,-1):
			if prime[i]==1:
				cnt+=1
		print(cnt)
		if count==30:
			break

main()

