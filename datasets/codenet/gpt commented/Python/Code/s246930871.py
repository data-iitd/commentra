# Read input values for N, A, and B from the user
N, A, B = map(int, input().split())

# Calculate the total number of complete cycles of (A + B) that can fit into N
# Each cycle contributes A to the answer
# The integer division N // (A + B) gives the number of complete cycles
# Multiply by A to get the total contribution from complete cycles
total_cycles_contribution = A * (N // (A + B))

# Calculate the remaining items after accounting for complete cycles
# Use the modulus operator to find the leftover items
remaining_items = N % (A + B)

# The minimum of A and the remaining items gives the additional contribution
# This accounts for the case where there are not enough remaining items to fill A
additional_contribution = min(A, remaining_items)

# The final answer is the sum of contributions from complete cycles and the additional contribution
ans = total_cycles_contribution + additional_contribution

# Print the final result
print(ans)
