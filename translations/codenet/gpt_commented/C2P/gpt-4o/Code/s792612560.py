# Declare an integer variable 'n' for input and an unsigned long long int 'm' for storing the result
n = int(input())

# Initialize 'm' with the value of 'n'
m = n

# Decrease 'n' by 1 to prepare for the factorial calculation
n -= 1

# Loop to calculate the factorial of 'n' (m = n!)
while n > 1:
    # Multiply 'm' by the current value of 'n'
    m *= n
    n -= 1

# Print the calculated factorial value stored in 'm'
print(m)

# <END-OF-CODE>
