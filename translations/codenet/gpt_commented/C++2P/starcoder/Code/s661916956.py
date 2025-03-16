# Include the iostream library for input and output
# Include the algorithm library for the swap function

# Declare three integer variables to hold the input values
a = int(input())
b = int(input())
c = int(input())

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

# 