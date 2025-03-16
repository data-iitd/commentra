# Declare variables to hold input values and results
A, B = map(int, input().split())

# Calculate the sum, difference, and product of A and B
C = A + B  # Sum of A and B
D = A - B  # Difference of A and B
E = A * B  # Product of A and B

# Initialize max with the value of C (sum)
max_value = C

# Compare max with D (difference) and update if D is greater
if max_value < D:
    max_value = D

# Compare max with E (product) and update if E is greater
if max_value < E:
    max_value = E

# Print the maximum value among sum, difference, and product
print(max_value)

# <END-OF-CODE>
