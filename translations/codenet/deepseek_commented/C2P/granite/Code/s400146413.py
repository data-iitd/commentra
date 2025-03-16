
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
  while( S[i]!= key ):
    i += 1
    if( i >= n  ):
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
  n = int(input())
  S = list(map(int, input().split()))

  q = int(input())
  T = list(map(int, input().split()))
 
  count = 0
  for j in range(q):
    key = T[j]
    if(linearsearch(S, n, key) == 0):
      count += 1
  
  print(count)
  
  return 0

