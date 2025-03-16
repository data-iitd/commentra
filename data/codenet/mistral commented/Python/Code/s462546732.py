
# Assign the first two elements of the input string to variables a and b respectively
a, b = input().split(" ")

# Convert both variables to integers
a = int(a)
b = int(b)

# Check if the value of a is less than or equal to the value of b
if a <= b:
    # If the condition is true, print the value of a
    print(a)
else:
    # If the condition is false, print the value of a minus one
    print(a-1)