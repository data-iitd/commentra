# Read two integers N and M from input, where N is the total number of items and M is not used in the calculation
N, M = map(int, input().split())

# Read a list of integers A from input, representing the quantities of items
A = map(int, input().split())

# Calculate the sum of the quantities in list A
A_sum = sum(A)

# Determine the remaining items by subtracting A_sum from N
# If the result is non-negative, print it; otherwise, print "-1"
print(N - A_sum if N - A_sum >= 0 else "-1")
