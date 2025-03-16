# Import necessary libraries
import sys

def main():
    # Read input string from standard input
    z = input().strip()  # Use strip to remove any leading/trailing whitespace
    a = len(z)  # Calculate the size of the string

    # Iterate through the string
    for i in range(a - 1):
        # Check if any two consecutive characters are the same
        if z[i] == z[i + 1]:
            print("Bad")  # Print "Bad" if a pair is found and exit
            return

    print("Good")  # Print "Good" if no pair is found

if __name__ == "__main__":
    main()

# <END-OF-CODE>
