# Importing the necessary module for string manipulation
import sys

def main():
    # Reading input from the user
    n, s = sys.stdin.read().splitlines()
    n = int(n)  # Converting the first line to an integer
    # Counting the occurrences of "ABC" in s and printing the result
    print(s.count("ABC"))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
