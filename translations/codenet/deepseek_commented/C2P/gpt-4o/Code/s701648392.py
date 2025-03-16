# Include the standard input-output library
def main():  # Define the main function, the entry point of the program
    a, b, c = map(int, input().split())  # Read three integer inputs from the user and store them in a, b, and c
    if a < b and b < c:  # Check if a is less than b and b is less than c
        print("Yes")  # If true, print "Yes"
    else:  # Otherwise
        print("No")  # Print "No"

if __name__ == "__main__":  # Ensure the main function runs when the script is executed
    main()

# <END-OF-CODE>
