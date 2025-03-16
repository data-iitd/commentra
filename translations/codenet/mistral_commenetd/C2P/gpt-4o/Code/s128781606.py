# Include the standard input/output library

def main():  # The entry point of the program
    A, B = map(int, input().split())  # Read two integers from the standard input and store them in variables A and B

    C = A + B  # Compute the sum of A and B and store the result in variable C
    D = A - B  # Compute the difference of A and B and store the result in variable D
    E = A * B  # Compute the product of A and B and store the result in variable E

    max_value = C  # Initialize max_value with the value of C

    if max_value < D:  # Check if D is greater than max_value
        max_value = D  # If so, update max_value with the value of D

    if max_value < E:  # Check if E is greater than max_value
        max_value = E  # If so, update max_value with the value of E

    print(max_value)  # Print the maximum value to the standard output

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
