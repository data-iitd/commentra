# Include the standard input output library

def main():
    # Declare the main function

    a, b, c, d = map(int, input().split())
    # Read four integers from the standard input and store them in variables a, b, c, and d

    i = a * b
    # Multiply variables a and b and store the result in variable i

    j = c * d
    # Multiply variables c and d and store the result in variable j

    if i > j:
        # Check if the value of i is greater than j
        print(i)
        # If true, print the value of i
    else:
        # If the condition in the if statement is false
        print(j)
        # Print the value of j

if __name__ == "__main__":
    main()
    # End the main function

# <END-OF-CODE>
