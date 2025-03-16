
import sys

# Function to read an integer from the standard input
def readInt():
    # Reading the input value of K
    return int(input())

# Function to find the answer
def solve():
    # Reading the input value of K
    K = readInt()

    # Checking if K is even or multiple of 5, returning -1 if true
    if K % 2 == 0 or K % 5 == 0:
        return -1

    # If K is multiple of 7, dividing it by 7 and multiplying it by 9
    if K % 7 == 0:
        K /= 7
    K *= 9

    # Initializing the answer variable and the remainder variable
    ans = 1
    remainder = 10 % K

    # Using a while loop to find the answer
    while remainder!= 1:
        ans += 1 # Incrementing the answer variable
        remainder = remainder * 10 % K # Updating the remainder variable

    # Returning the answer
    return ans

# Main function to call the solve function and print the result
if __name__ == "__main__":
    print(solve())

