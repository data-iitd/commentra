#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

# Function declarations
def Partition(C, A, p, r):

  i, j = p - 1, p
  x = C[r]
  y = A[r]

  while j < r:
    if A[j] <= y:
      i = i + 1
      tmpN = A[j]
      tmpC = C[j]
      A[j] = A[i]
      C[j] = C[i]
      A[i] = tmpN
      C[i] = tmpC
    j = j + 1

  tmpN = A[i+1]
  tmpC = C[i + 1]
  A[i+1] = A[r]
  C[i+1] = C[r]
  A[r] = tmpN
  C[r] = tmpC

  return i+1

def Quicksort(C, A, p, r):

  if p < r:
    q = Partition(C, A, p, r)
    Quicksort(C, A, p, q-1)
    Quicksort(C, A, q+1, r)

def Merge(MC, MN,left,mid,right):

  n1 = mid - left + 1
  n2 = right - mid
  LN = [0] * (n1 + 1)
  RN = [0] * (n2 + 1)
  LC = [0] * (n1 + 1)
  RC = [0] * (n2 + 1)

  for i in range(1, n1 + 1):
    LN[i] = MN[left + i - 1]
    LC[i] = MC[left + i - 1]

  for i in range(1, n2 + 1):
    RN[i] = MN[mid + i]
    RC[i] = MC[mid + i]

  LN[n1+1] = 1000000000
  RN[n2+1] = 1000000000

  i, j, k = 1, 1, left
  while i <= n1 and j <= n2:
    if LN[i] <= RN[j]:
      MN[k] = LN[i]
      MC[k] = LC[i]
      i = i + 1
    else:
      MN[k] = RN[j]
      MC[k] = RC[j]
      j = j + 1
    k = k + 1

  del LN
  del RN
  del LC
  del RC

def Merge_Sort(MC, MN,left,right):
    mid = (left + right)/2
    if left < right:
        Merge_Sort(MC,MN,left,mid)
        Merge_Sort(MC,MN,mid+1,right)
        Merge(MC,MN,left,mid,right)

# Main function
def main():

  A = [0] * (MAX + 1)
  C = [0] * (MAX + 1)
  MC = [0] * (MAX + 1)
  MN = [0] * (MAX + 1)

  n = int(input())

  for i in range(1, n + 1):
    C[i], A[i] = input().split()
    MC[i] = C[i]
    MN[i] = A[i]

  p = 1
  Quicksort(C, A, p, n)

  Merge_Sort(MC,MN,1,n)

  count = 0
  for i in range(1, n + 1):
    if MN[i] == A[i] and MC[i] == C[i]:
      count = count + 1

  if count == n:
    print("Stable")
  else:
    print("Not stable")

  for i in range(1, n + 1):
    print(C[i], A[i])

main()

