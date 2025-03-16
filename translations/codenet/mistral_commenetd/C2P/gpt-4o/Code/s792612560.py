# Declare variables
n = int(input())
# Assign the value of n to m for later use
m = n
# Decrement n by 1
n -= 1

# Loop through n-1 times to calculate the factorial
while n > 1:
    # Multiply m with current value of n
    m *= n
    n -= 1

# Print the result
print(m)
# Return 0 to indicate successful execution
# In Python, we don't need to explicitly return 0
# <END-OF-CODE>
