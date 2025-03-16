# Import the sys module for standard input
import sys

# Define the main function
def main():
    # Read a string input from the standard input
    s = sys.stdin.readline().strip()

    # Check if the first three characters of the string "s" form an identical sequence
    if (s[0] == s[1] == s[2]) or (s[1] == s[2] == s[3]):
        # If the condition is true, print "Yes" to the standard output
        print("Yes")
    else:
        # If the condition is false, print "No" to the standard output
        print("No")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
