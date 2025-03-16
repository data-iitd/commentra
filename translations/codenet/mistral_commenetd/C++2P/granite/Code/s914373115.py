

# Function A definition goes here
def A():
    pass

# Function B definition goes here
def B():
    x = int(input()) # Read an integer 'x' from the standard input
    sum = 100 # Initialize'sum' with the value 100
    i = 0 # Initialize variable 'i' with the value 0

    # Calculate the number of iterations required to reach or exceed 'x'
    while sum < x:
        sum += sum // 100 # Update'sum' by adding the result of dividing'sum' by 100
        i += 1 # Increment 'i' by 1

    # Print the number of iterations required to reach or exceed 'x'
    print(i)

# Function C definition goes here
def C():
    pass

# Function D definition goes here
def D():
    pass

# Call function B
B()

# 