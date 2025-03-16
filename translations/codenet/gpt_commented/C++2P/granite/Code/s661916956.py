
a, b, c = map(int, input().split()) # Read three integers from the user and assign them to variables a, b, and c

if a > b: # Check if 'a' is greater than 'b', if so, swap their values
    a, b = b, a

if b > c: # Check if 'b' is greater than 'c', if so, swap their values
    b, c = c, b

if a > b: # Check again if 'a' is greater than 'b', if so, swap their values
    a, b = b, a

print(a, b, c) # Output the sorted values of a, b, and c

