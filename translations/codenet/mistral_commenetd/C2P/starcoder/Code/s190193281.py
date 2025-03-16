
#include<stdio.h>
#define N 1000000
#define Q 50000

def binarySearch(S,key):
  left = 0
  right = len(S)-1
  while(left <= right):
    mid = (left+right)/2
    if(S[mid] == key):
      return 1
    elif(key < S[mid]):
      right = mid-1
    else:
      left = mid+1
  return 0

n = int(input("Enter the size of the array: "))
S = [int(input("Element %d: "%(i+1))) for i in range(n)]
q = int(input("Enter the number of queries: "))
T = [int(input("Query %d: "%(i+1))) for i in range(q)]
c = 0
for i in range(q):
  if(binarySearch(S,T[i])==1):
    c += 1
print("Number of queries present in the array: %d"%(c))

