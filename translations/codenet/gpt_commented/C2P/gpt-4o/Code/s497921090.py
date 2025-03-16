# Declare variables
n = int(input())  # Read an unsigned long long integer from user input

# Calculate the number of ways to choose 2 items from n items
# This is done using the formula: b = n * (n - 1) / 2
b = (n * (n - 1)) // 2

# Print the result
print(b)

# Return 0 to indicate successful execution
# In Python, we don't need to explicitly return 0
# <END-OF-CODE>
