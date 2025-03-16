# Declare three integer variables A, B, and C
def main():
    # Read three integers from the standard input
    A, B, C = map(int, input().split())

    # Check if A is less than C and C is less than B
    if A < C < B:
        # If condition is true, print "Yes" to the standard output
        print("Yes")
    # Else if condition checks if A is greater than C and C is greater than B
    elif A > C > B:
        # If condition is true, print "Yes" to the standard output
        print("Yes")
    # Else condition is executed when neither first nor second condition is true
    else:
        # If condition is false, print "No" to the standard output
        print("No")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
