
import math

# Function to calculate the sum of digits of a number recursively
def keta(s):
    # If the length of the string is less than 2, return the integer value of the string
    if len(s) < 2:
        return int(s)
    # Calculate the sum of the digits in the string
    n = sum(map(int, s))
    # Recursively call keta with the sum of digits converted back to a string
    return keta(str(n))

# Main function to execute the program
def main():
    # Read the input number as a string
    N = input()
    # Check if the sum of the digits of N, recursively calculated, is divisible by 9
    if keta(N) % 9 == 0:
        # Print "Yes" if the sum is divisible by 9
        print("Yes")
    else:
        # Print "No" if the sum is not divisible by 9
        print("No")

# Check if the script is the main program and execute the main function
if __name__ == "__main__":
    main()

