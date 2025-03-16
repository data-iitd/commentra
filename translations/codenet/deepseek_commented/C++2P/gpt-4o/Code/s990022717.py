# Read the values of n, k, x, and y from the standard input
n, k, x, y = map(int, input().split())

# Initialize the sum to 0, which will accumulate the total cost
total_cost = 0

# Loop through numbers from 1 to n
for i in range(1, n + 1):
    # If the current number i is greater than k, add y to total_cost
    # Otherwise, add x to total_cost
    if i > k:
        total_cost += y
    else:
        total_cost += x

# Output the total cost, which is the cost calculated based on the input parameters
print(total_cost)

# <END-OF-CODE>
