
# Include the standard input/output library
import sys

# Start of the main function
def main():
    # Declare four integer variables to store months and days
    m1, d1, m2, d2 = 0, 0, 0, 0

    # Read four integers from the standard input
    m1, d1, m2, d2 = map(int, sys.stdin.readline().split())

    # Check if the first two months are equal or not
    if m1!= m2:
        # If the months are not equal, print "1" to the standard output
        print("1")
    else:
        # If the months are equal, print "0" to the standard output
        print("0")

# Call the main function
if __name__ == "__main__":
    main()

