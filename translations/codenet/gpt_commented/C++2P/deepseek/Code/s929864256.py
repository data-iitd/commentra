a, b = map(int, input().split())

# Calculate the maximum of the sum, difference, and product of a and b
print(max(a + b, max(a - b, a * b)))

