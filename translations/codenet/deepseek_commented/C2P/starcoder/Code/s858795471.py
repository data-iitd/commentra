
#include<stdio.h>
def search(A,n,key):
    i=0
    # Add the key to the end of the array to handle the case where the key is not found
    A[n]=key
    # Loop until the key is found in the array
    while(A[i]!=key) i+=1
    # Return 1 if the key is found, otherwise return 0
    return i!=n

def main():
    n,A,q,key,sum=0,[],0,0,0
    i=0
    # Read the size of the array
    n=int(raw_input())
    # Read the array elements
    for i in range(n): A.append(int(raw_input()))
    # Read the number of queries
    q=int(raw_input())
    # Process each query
    for i in range(q):
	key=int(raw_input())
	# Perform the search operation for the current query element
	if(search(A,n,key)): sum+=1
    # Print the count of successful searches
    print sum

    return 0

