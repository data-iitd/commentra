# Declare an integer list 'v' of size 10 and an integer variable 'sum' to store the sum of list elements.
def main():
    v = [0] * 10  # Declare an integer list 'v' of size 10.
    sum = 0       # Declare an integer variable 'sum' and initialize it to zero.

    # Read 10 integers from the user and store them in the list 'v'.
    for i in range(10):
        v[i] = int(input(f"Enter the value for index {i}: "))
        # Read an integer value from the user and store it in the current index of the list 'v'.

    # Calculate the sum of all elements in the list 'v'.
    for i in range(10):
        sum += v[i]
        # Add the value of the current element in the list 'v' to the variable 'sum'.

    # Print the sum of all elements in the list 'v'.
    print(sum)
    # Display the sum of all elements in the list 'v'.

if __name__ == "__main__":
    main()
    # Indicate successful termination of the program.

# <END-OF-CODE>
