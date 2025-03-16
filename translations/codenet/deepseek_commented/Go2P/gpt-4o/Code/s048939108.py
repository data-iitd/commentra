import sys

# Main function starts here
def main():
    # Read the next string from the input
    S = input().strip()
    # Check if the string S starts with the prefix "YAKI"
    if S.startswith("YAKI"):
        # If it does, print "Yes"
        print("Yes")
    else:
        # Otherwise, print "No"
        print("No")

# Helper function to find the minimum of two integers
def min(a, b):
    return b if a > b else a

# Helper function to find the maximum of two integers
def max(a, b):
    return a if a > b else b

# Function to read the next integer from the input
def next_int():
    return int(input().strip())

# Function to read the next array of integers from the input
def next_int_array():
    return list(map(int, input().strip().split()))

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
