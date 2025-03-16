# Include the standard input/output library header file

def main():
    a, b, c = map(int, input().split())
    # Use the input function to read three integers from the standard input
    # and assign them to the variables a, b, and c respectively

    if a < b and b < c:
        print("Yes")
        # If the condition a < b and b < c is true, print the string "Yes"
        # followed by a newline character to the standard output
    else:
        print("No")
        # If the condition a < b and b < c is false, print the string "No"
        # followed by a newline character to the standard output

if __name__ == "__main__":
    main()
    # End the main function with a return statement of 0, indicating that
    # the program has run successfully

# <END-OF-CODE>
