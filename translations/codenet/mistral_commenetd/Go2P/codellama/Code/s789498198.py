
import sys

# Initialize scanner and read the first line
sc = sys.stdin.readline()

# Main function
def main():
    # Read the first two integers from the input
    A, B = map(int, sc.split())

    # Check if the sum of A and B is even
    if (A+B)%2 == 0:
        # If it is, print the result (the average)
        print((A + B) / 2)
        return
    # If the sum is odd, print "IMPOSSIBLE"
    print("IMPOSSIBLE")

# Call the main function
main()

