
#include <stdio.h>

int A[1000000], n;

/* 
 * binarySearch function performs a binary search on the array A to find a given key.
 * It returns 1 if the key is found, otherwise it returns 0.
 */
def binarySearch(key):
  left = 0
  right = n
  while left < right:
    mid = (left + right) // 2
    if key == A[mid]: return 1 # keyを発見
    if key > A[mid]: left = mid + 1 # 後半を探索
    else: right = mid # 前 halfを探索
  return 0

/* 
 * main function is the entry point of the program.
 * It reads the size of the array and the elements of the array from the user.
 * It then reads the number of queries and performs binary search for each query.
 * Finally, it prints the number of elements found.
 */
def main():
  i = 0
  q = 0
  k = 0
  sum = 0
  n = int(input())
  for i in range(n):
    A[i] = int(input())
  q = int(input())
  for i in range(q):
    k = int(input())
    if binarySearch(k):
      sum += 1
  print(sum)

