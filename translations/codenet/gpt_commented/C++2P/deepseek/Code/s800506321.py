# Declare variables to hold input values and intermediate results
n, k = map(int, input().split())

# Calculate the number of items in each group (integer division)
x = n // k

# Calculate the remainder to check if there are leftover items
y = n % k

# Check if there are leftover items after dividing into groups
if y != 0:
    # If there are leftovers, set z to 1 (indicating at least one group has one extra item)
    z = 1
else:
    # If there are no leftovers, set z to 0 (indicating all groups are even)
    z = 0

# Output the result (0 or 1) indicating if there are leftover items
print(z)
