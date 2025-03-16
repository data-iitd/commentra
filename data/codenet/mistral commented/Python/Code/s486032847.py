# Import the math module for using mathematical functions
import math

# Define a helper function 'keta' to calculate the sum of digits of a number recursively
def keta(s):
    # Base case: if the length of the string 's' is less than 2, return the integer value of 's'
    if len(s) < 2:
        return int(s)
    # Calculate the sum of digits of the number represented by the string 's'
    n = sum(map(int, s))
    # Recursively call the 'keta' function with the string representation of the sum
    return keta(str(n))

# Define the main function to read input and process it
def main():
    # Read a single line input as a string
    N = input()
    # Split the input string into a list of integers using map and list functions
    # N, X, T = list(map(int, input().split()))
    
    # Check if the sum of digits of the number 'N' is divisible by 9
    if keta(str(N)) % 9 == 0:
        # If it is, print 'Yes'
        print("Yes")
    else:
        # If it's not, print 'No'
        print("No")

# Call the main function if the script is run as the main program
if __name__ == "__main__":
    main()
