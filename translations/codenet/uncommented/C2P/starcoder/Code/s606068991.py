
def white(n,A):
	for i in range(n-1):
		print(A[i],end=" ")
	print(A[i])

def insertionsort(n,A):
	for i in range(n):
		for j in range(i):
			if(A[i]<A[j]):
				a=A[i]
				A[i]=A[j]
				A[j]=a
		white(n,A)

n=int(input())
A=[]
for i in range(n):
	A.append(int(input()))
insertionsort(n,A)

