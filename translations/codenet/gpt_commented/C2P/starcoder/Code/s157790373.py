#define LEN 300
#define TRUE 1
#define FALSE -1

# Function prototype for the recursive solve function
def solve(i, m):
  # Base case: if index exceeds the number of elements
  if(i > n): return FALSE
  # Base case: if the remaining sum is negative
  elif(m < 0): return FALSE
  # Base case: if the remaining sum is zero (solution found)
  elif(m == 0 or m - A[i + 1] == 0):
    flag = TRUE # Set flag to TRUE indicating a solution is found
    return TRUE # Return TRUE
  else:
    # Recursive case: do not use the current element A[i]
    solve(i + 1, m)
    # Recursive case: use the current element A[i]
    solve(i + 1, m - A[i])

# Main function
def main():
  global n, A, flag # Global variables: n for the number of elements, A for the array of elements, flag to indicate if a solution is found
  q, M # q for the number of queries, M for the target sum
  i, j, k # Loop variables

  # Read the number of elements in the array
  n = int(input())
  # Read the elements into the array A
  for i in range(n): A[i] = int(input())

  # Read the number of queries
  q = int(input())
  # Process each query
  for i in range(q):
    # Read the target sum for the current query
    M = int(input())
    flag = FALSE # Reset flag for each query

    # Call the solve function to check if a subset sums to M
    solve(-1, M)
    # Output the result based on the flag
    if(flag == TRUE): print("yes")
    else: print("no")

# Global variables: n for the number of elements, A for the array of elements, flag to indicate if a solution is found
n = LEN
A = [0] * LEN
flag = FALSE

# Main function
if __name__ == "__main__": main()

