# Declare three long long integers to store input values
def main():
    # Read the values of a, b, and c from the standard input
    a, b, c = map(int, input().split())

    # Calculate the difference between c and the sum of a and b
    d = c - a - b

    # Check if d is positive and if the product of the squares of a and b is less than d squared
    if d > 0 and (4 * a * b) < (d * d):
        # If the condition is true, print "Yes" to the standard output
        print("Yes")
    else:
        # If the condition is false, print "No" to the standard output
        print("No")

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
