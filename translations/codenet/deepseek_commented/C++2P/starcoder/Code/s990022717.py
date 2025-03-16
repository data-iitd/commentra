# Read the values of n, k, x, and y from the standard input
n, k, x, y = map(int, input().split())

# Initialize the sum to 0, which will accumulate the total cost
sum = 0

# Loop through numbers from 1 to n
for i in range(1, n+1):
  # If the current number i is greater than k, add y to sum
  # Otherwise, add x to sum
  if i > k:
    sum += y
  else:
    sum += x

# Output the total sum, which is the cost calculated based on the input parameters
print(sum)

# Return 0 to indicate successful execution
return 0

