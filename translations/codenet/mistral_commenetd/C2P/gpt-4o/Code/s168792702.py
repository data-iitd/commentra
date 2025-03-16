# Include the standard input/output library

def main():
    # Read three integers from the standard input and store them in variables a, b, and c
    a, b, c = map(int, input().split())

    # Check if the condition a < b and b < c is true. If it is, print "Yes". Otherwise, print "No"
    if a < b < c:
        print("Yes")  # If the condition is true, print "Yes"
    else:
        print("No")   # If the condition is false, print "No"

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
