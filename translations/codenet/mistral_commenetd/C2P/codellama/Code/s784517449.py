#include <stdio.h>

A = [0] * 1000000 # initialize an integer array A of size 1,000,000
n = 0 # initialize an integer n

def binarySearch(key): # function to perform binary search
  left = 0 # initialize left index to 0
  right = n # initialize right index to the last index of the array
  mid = 0 # initialize middle index

  while left < right: # while left index is less than right index
    mid = (left + right) // 2 # calculate middle index
    if key == A[mid]: # if key is equal to the middle element
      return 1 # return 1 to indicate key is found
    if key > A[mid]: # if key is greater than the middle element
      left = mid + 1 # update left index to search in the right half
    else: # if key is less than the middle element
      right = mid # update right index to search in the left half
  return 0 # if key is not found, return 0

n = int(input()) # read the number of elements in the array from the standard input
for i in range(n): # for loop to read and store the elements of the array
  A[i] = int(input())
q = int(input()) # read the number of queries from the standard input
sum = 0 # initialize sum
for i in range(q): # for loop to perform binary search for each query
  k = int(input())
  if binarySearch(k): # if key is found in the array
    sum += 1 # increment sum by 1
print(sum) # print the number of queries with a matching element in the array

