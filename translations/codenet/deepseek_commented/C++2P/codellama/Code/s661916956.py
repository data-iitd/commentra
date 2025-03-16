# Read three integers from the standard input
a, b, c = map(int, input().split())

# Sort the integers in ascending order
if a > b:
    a, b = b, a
if b > c:
    b, c = c, b
if a > b:
    a, b = b, a

# Print the sorted integers
print(a, b, c)

