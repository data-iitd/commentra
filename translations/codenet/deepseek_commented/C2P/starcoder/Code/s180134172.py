#include<stdio.h>
def main():
    n,k,p,i,j,l,m,o=0,0,[],0,0,0,0,0,0
    # Read the number of elements (n) and the number of elements to sum (k)
    n,k=map(int,input().split())
    # Read n integers and store them in the array p
    for i in range(n):
        p.append(int(input()))
    # Perform selection sort on the array p
    for i in range(n):
        l=i
        for j in range(i+1,n):
            if(p[j]<p[l]):
                l=j
        if(l!=i):
            m=p[i]
            p[i]=p[l]
            p[l]=m
    # Sum the first k elements of the sorted array
    for i in range(k):
        o +=p[i]
    # Print the sum of the first k elements
    print(o)

