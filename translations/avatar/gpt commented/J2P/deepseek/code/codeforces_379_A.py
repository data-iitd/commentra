# Reading two integers from the user
a = int(input())  # The initial amount
b = int(input())  # The divisor

# Initializing the result with the value of 'a'
res = a

# Loop to perform the division and accumulate the result
while a >= b:
    # Add the quotient of a divided by b to the result
    res += (a // b)
    
    # Update 'a' to be the sum of the quotient and the remainder
    a = (a // b) + (a % b)

# Output the final result
print(res)
