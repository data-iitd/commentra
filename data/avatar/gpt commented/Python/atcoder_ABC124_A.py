# Read two integers from input and assign them to variables a and b
a, b = map(int, input().split())

# Initialize a variable c to accumulate the result
c = 0

# Loop for 2 iterations
for i in range(2):
    # Add the maximum of a and b to c
    c += max(a, b)
    
    # Decrease the larger of the two numbers (a or b) by 1
    if a >= b:
        a -= 1  # If a is greater than or equal to b, decrement a
    else:
        b -= 1  # Otherwise, decrement b

# Print the final accumulated value of c
print(c)
