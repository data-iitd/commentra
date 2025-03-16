
# Function A is not defined in the provided code.
def A():
    # Function implementation here (if needed)
    pass

# Function B is defined to take input and calculate the number of iterations.
def B():
    x = int(input())
    i = 0  # Initialize i to 0
    sum = 100  # Initialize sum to 100
    while sum < x:
        sum += sum // 100  # Increment sum by 1%
        i += 1
    print(i)  # Output the number of iterations

# Function C is not defined in the provided code.
def C():
    # Function implementation here (if needed)
    pass

# Function D is not defined in the provided code.
def D():
    # Function implementation here (if needed)
    pass

# Main function calls the B function.
if __name__ == "__main__":
    B()

