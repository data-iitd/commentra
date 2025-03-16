# Importing the standard input output library (not needed in Python)
# Starting the main function
def main():
    # Declaring three integer variables a, b, and c
    a, b, c = map(int, input().split())  # Reading three integers from the standard input and storing them in variables a, b, and c

    # Starting the if condition block
    if a < b and b < c:  # Checking if a is less than b and b is less than c
        print("Yes")  # If the condition is true, print "Yes" to the standard output
    else:  # Starting the else condition block
        print("No")  # If the condition is false, print "No" to the standard output

# Calling the main function
if __name__ == "__main__":
    main()  # Ending the main function

# <END-OF-CODE>
