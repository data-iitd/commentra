
#include<stdio.h>
#define N 1000000
#define Q 50000

int n,S[N],T[Q];

# Function to perform binary search on an array
def binarySearch(key):
  left = 0
  right = n
  while left < right:
    mid = (left+right)/2
    if S[mid] == key:
      return 1
    elif key < S[mid]:
      right = mid
    else:
      left = mid+1
  return 0

def main():
  i,j,q,c=0

  # Read the size of the array
  print("Enter the size of the array: ")
  n = int(input())

  # Allocate memory for the array
  S = [0]*n

  # Read the elements of the array
  print("Enter %d integers:\n"%n)
  for i in range(n):
    print("Element %d: "%(i+1))
    S[i] = int(input())

  # Read the number of queries
  print("Enter the number of queries: ")
  q = int(input())

  # Allocate memory for the queries
  T = [0]*q

  # Read the queries
  print("Enter %d integers to be searched:\n"%q)
  for i in range(q):
    print("Query %d: "%(i+1))
    T[i] = int(input())

  # Check if the query is present in the array
  for i in range(q):
    if binarySearch(T[i])==1:
      c+=1

  # Print the number of queries present in the array
  print("Number of queries present in the array: %d\n"%c)

  # Free the allocated memory
  del S
  del T

if __name__ == "__main__":
  main()

