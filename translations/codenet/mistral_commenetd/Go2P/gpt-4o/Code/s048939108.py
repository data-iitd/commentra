import sys

# Initialize a new scanner
def main():
    # Read the first string from the standard input
    S = input().strip()

    # Check if the string starts with "YAKI"
    if S.startswith("YAKI"):
        print("Yes")  # Print "Yes" if the condition is true
    else:
        print("No")   # Print "No" if the condition is false

# Minimum function
def min(a, b):
    # Determine the minimum of two integers
    return b if a > b else a

# Maximum function
def max(a, b):
    # Determine the maximum of two integers
    return a if a > b else b

# Scanner class definition is not needed in Python as input() handles it

if __name__ == "__main__":
    main()

# <END-OF-CODE>
