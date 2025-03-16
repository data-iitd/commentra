# Read three integers from the user
a, b, c = map(int, input().split())

# Check if 'a' is greater than 'b', if so, swap their values
if a > b:
    a, b = b, a

# Check if 'b' is greater than 'c', if so, swap their values
if b > c:
    b, c = c, b

# Check again if 'a' is greater than 'b', if so, swap their values
if a > b:
    a, b = b, a

# Output the sorted values of a, b, and c
print(a, b, c)

# <END-OF-CODE>
