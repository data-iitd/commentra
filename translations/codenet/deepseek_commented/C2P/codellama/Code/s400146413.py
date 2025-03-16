#include<stdio.h>

# Linear Search Function
# Purpose: This function performs a linear search to find the key in the array S.
# Parameters:
#   - S[]: The array to be searched.
#   - n: The size of the array S.
#   - key: The value to be searched for.
# Return Value: Returns 1 if the key is not found, otherwise returns 0.
def linearsearch(S, n, key):
  i = 0
  count = 0
  while( S[i] != key ):
    i += 1
    if( i >= n ):
      count = 1
      return count
  return count

# Main Function
# Purpose: This function reads two arrays S and T, and counts the number of elements in T that are present in S using the linearsearch function.
# Variables:
#   - i, j: Loop counters.
#   - n, q: Sizes of arrays S and T.
#   - S[]: The first array to be read.
#   - T[]: The second array to be read.
#   - count: Counter for the number of elements found.
#   - key: The current element being searched for in S.
def main():
  i, j, n, q, S, T, count, key
  scanf("%d", &n)
  for(i = 0; i < n; i++):
    scanf("%d", &S[i])

  scanf("%d", &q)
  for(j = 0; j < q; j++):
    scanf("%d", &T[j])
 
  for( j = 0; j < q; j++):
    key = T[j]
    if(linearsearch(S, n, key) == 0):
      count += 1
 
  printf("%d\n", count)
  
  return 0

