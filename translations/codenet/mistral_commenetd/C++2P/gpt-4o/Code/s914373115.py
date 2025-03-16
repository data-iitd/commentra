def A():
    pass  # Function A definition goes here

def B():
    x = int(input())  # Read a long long integer 'x' from the standard input
    sum = 100  # Initialize 'sum' with the value 100
    i = 0  # Initialize iteration counter

    # Calculate the number of iterations required to reach or exceed 'x'
    while sum < x:
        sum += sum // 100  # Update 'sum' by adding the result of dividing 'sum' by 100
        i += 1  # Increment the iteration counter

    # Print the number of iterations required to reach or exceed 'x'
    print(i)

def C():
    pass  # Function C definition goes here

def D():
    pass  # Function D definition goes here

if __name__ == "__main__":
    B()  # Call function B

# <END-OF-CODE>
