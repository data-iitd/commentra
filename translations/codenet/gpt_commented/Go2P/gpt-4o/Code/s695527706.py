# Importing the necessary module for string manipulation
import sys

def main():
    # Read input values for n and s from the standard input
    n, s = sys.stdin.read().split()
    n = int(n)  # Convert n to an integer

    # Count and print the number of occurrences of the substring "ABC" in the string s
    print(s.count("ABC"))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
