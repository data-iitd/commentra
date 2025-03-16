
# Read input values from standard input
a, b = map(int, input().split())

# Calculate the maximum value among a+b, a-b, and a*b
result = max(a+b, max(a-b, a*b))

# Output the result to standard output
print(result)

# End of the program

