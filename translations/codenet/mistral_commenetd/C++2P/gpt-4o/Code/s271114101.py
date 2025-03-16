# This line includes the standard input-output library and makes the "std" namespace accessible without having to write "std::" before each standard library function or variable.

def main():  # The main function is the entry point of the program. It initializes the program and calls the function main().
    a, b, c = map(int, input().split())  # Read three integers from the standard input and assign them to the variables a, b, and c.
    # The following if statement checks if any of the following conditions are true:
    # (a + b) == c # If the sum of a and b is equal to c
    # (b + c) == a # If the sum of b and c is equal to a
    # (a + c) == b # If the sum of a and c is equal to b
    if (a + b == c) or (b + c == a) or (a + c == b):  # If any of the above conditions are true, the following code is executed.
        print("Yes")  # Output the string "Yes" to the standard output.
    else:  # If none of the above conditions are true, the following code is executed.
        print("No")  # Output the string "No" to the standard output.

if __name__ == "__main__":  # This line checks if the script is being run directly (not imported).
    main()  # Call the main function to execute the program.

# <END-OF-CODE>
