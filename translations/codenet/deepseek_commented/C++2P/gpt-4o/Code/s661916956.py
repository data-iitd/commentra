# Read three integers from the standard input
a, b, c = map(int, input().split())

# Sort the integers in ascending order
if a > b:
    a, b = b, a  # Swap a and b if a is greater than b
if b > c:
    b, c = c, b  # Swap b and c if b is greater than c
if a > b:
    a, b = b, a  # Swap a and b again to ensure a is not greater than b after the second swap

# Print the sorted integers
print(a, b, c)

# <END-OF-CODE>
