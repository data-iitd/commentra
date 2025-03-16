# Declare and initialize a variable 'n' with an integer value read from standard input
n = int(input())

# Declare and initialize two variables 'i' and 'j' with initial values 1 and 'n * n' respectively
i, j = 1, n * n

# Start the while loop with the condition 'i < j'
while i < j:
    # Print the current values of 'i' and 'j' on the standard output
    print(i, j)
    
    # Increment the value of 'i' by 1 in each iteration of the loop
    i += 1
    
    # Decrement the value of 'j' by 1 in each iteration of the loop
    j -= 1