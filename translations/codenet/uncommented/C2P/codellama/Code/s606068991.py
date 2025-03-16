#include<stdio.h>

def white(n,A):
	for i in range(0,n-1):
		print(A[i],end=" ")
	print(A[i])

def insertionsort(n,A):
	for i in range(0,n):
		for j in range(0,i):
			if A[i]<A[j]:
				a=A[i]
				A[i]=A[j]
				A[j]=a
		white(n,A)

n=int(input())
A=list(map(int,input().split()))
insertionsort(n,A)

