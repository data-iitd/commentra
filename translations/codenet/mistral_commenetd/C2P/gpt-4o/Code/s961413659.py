# Include the standard input/output library
def main():  # Start of the main function
    a, b = map(int, input().split())  # Read two integers from the standard input and store them in variables 'a' and 'b'

    # First if block: If 'a' is equal to 1, assign 14 to 'a'
    if a == 1:
        a = 14

    # Second if block: If 'b' is equal to 1, assign 14 to 'b'
    if b == 1:
        b = 14

    # Determine who wins based on the values of 'a' and 'b'
    if a < b:
        print("Bob")  # If 'a' is less than 'b', print "Bob"
    elif a > b:
        print("Alice")  # If 'a' is greater than 'b', print "Alice"
    else:
        print("Draw")  # If 'a' is equal to 'b', print "Draw"

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
