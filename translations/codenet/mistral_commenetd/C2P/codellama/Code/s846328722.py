#include<stdio.h> // Including the standard input/output library

// Function declaration for linear search
int linersearch(int [],int ,int );

int main(){
  int i, n; // Declaring variables i and n for array index and size
  int s[100000]; // Declaring an array s of size 100000
  int q, t; // Declaring variables q and t for number of queries and query elements
  int count = 0; // Initializing count to zero

  # Input the size of the array from user input
  n = int(input())

  # Input array elements into the array s
  for i in range(n):
    s[i] = int(input())

  # Input the number of queries from user input
  q = int(input())

  # Looping through each query
  for i in range(q):
    t = int(input()) # Input a query element from user input

    # Calling the linear search function to check if the query element is present in the array
    if linersearch(s,n,t): count += 1 # If the query element is present, increment the count

  # Printing the final count of query elements present in the array
  print(count)

  return 0
}

# Function definition for linear search
def linersearch(a,n,key):
  i = 0 # Initializing index i to zero

  # Adding the key to the end of the array for the case when the key is already present at the beginning
  a[n] = key

  # Linear search algorithm to find the index of the key in the array
  while a[i] != key:
    i += 1 # Incrementing index i until the key is found

  # Returning 1 if the key is found, and 0 otherwise
  return i != n

