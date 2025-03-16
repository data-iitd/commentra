
#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

// Function to search for a key in an array
def search(A,n,key):
    i=0
    # Add the key to the end of the array
    A[n]=key
    # Search for the key in the array using a while loop
    while(A[i]!=key):
        i+=1
    # Return 1 if the key was found before the end of the array, otherwise return 0
    return i!=n

def main():
    n=0 # Number of elements in the array
    A=[0]*(MAX+1) # Array to store the elements
    q=0 # Number of queries
    key=0 # Key to be searched for
    sum=0 # Variable to store the number of keys found
    i=0 # Loop counter

    # Read the number of elements in the array from the user
    n=int(input())
    # Read the elements of the array from the user
    for i in range(n):
        A[i]=int(input())
    # Read the number of queries from the user
    q=int(input())
    # For each query, search for the key in the array and if it is found, increment the sum
    for i in range(q):
        key=int(input()) # Read the key to be searched for
        # Call the search function to find the key in the array
        if(search(A,n,key)):
            sum+=1 # If the key is found, increment the sum
    # Print the number of keys found
    print(sum)

if __name__ == "__main__":
    main()

