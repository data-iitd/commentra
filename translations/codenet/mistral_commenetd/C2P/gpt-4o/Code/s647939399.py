# Declare variables
def main():
    c = [0] * 256  # Initialize array c with zeros

    i = 0  # Initialize index i

    # Read input values of a, m, and b from the user
    while True:
        user_input = input("Enter 'a m b' or '?' to terminate: ")
        if user_input == '?':
            break
        
        a, m, b = user_input.split()
        a = int(a)
        b = int(b)

        # Perform arithmetic operations based on the operator m
        if m == '+':
            c[i] = a + b  # Store the result of addition in the array c
        elif m == '-':
            c[i] = a - b  # Store the result of subtraction in the array c
        elif m == '*':
            c[i] = a * b  # Store the result of multiplication in the array c
        elif m == '/':
            c[i] = a // b  # Store the result of division in the array c (using integer division)

        i += 1  # Increment index

    # Print the results of the arithmetic operations
    for j in range(i):
        print(c[j])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
