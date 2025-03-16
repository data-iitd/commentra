# Define the main function
def main():
    # Read four integers from the standard input
    a, b, c, d = map(int, input().split())
    
    # Check if the sum of a and b is greater than the sum of c and d
    if a + b > c + d:
        print("Left")  # If true, print "Left"
    elif a + b < c + d:
        print("Right")  # If true, print "Right"
    else:
        print("Balanced")  # If neither condition is true, print "Balanced"

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
