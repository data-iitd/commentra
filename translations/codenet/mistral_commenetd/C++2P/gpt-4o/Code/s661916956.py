# Initialize variables a, b, and c with user input
a, b, c = map(int, input().split())

# Check if a is greater than b and swap if necessary
if a > b:
    a, b = b, a

# Check if b is greater than c and swap if necessary
if b > c:
    b, c = c, b

# Check if a is greater than b again and swap if necessary
if a > b:
    a, b = b, a

# Print the sorted values of a, b, and c
print(a, b, c)

# <END-OF-CODE>
