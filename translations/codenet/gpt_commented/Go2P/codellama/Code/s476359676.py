
# Import the necessary libraries
import sys

# Function to read the next string from input
def nextStr():
    return sys.stdin.readline().strip()

# Function to read the next integer from input
def nextInt():
    return int(nextStr())

# Function to read the next integer from input
def nextInts():
    return [int(x) for x in nextStr().split()]

# Main function
def main():
    # Read the number of integers to process
    n = nextInt()

    # Initialize variables for the answer and the previous integer
    ans = 0
    aPrev = 0

    # Loop through each integer input
    for i in range(n):
        a = nextInt() # Read the next integer

        # Check conditions based on the current and previous integers
        if a > i or a > aPrev+1: # If the current integer is greater than the index or previous integer + 1
            print(-1) # Print -1 and exit if the condition is met
            return
        elif a == aPrev+1: # If the current integer is exactly one more than the previous integer
            ans += 1 # Increment the answer
        else: # For all other cases
            ans += a # Add the current integer to the answer
        aPrev = a # Update the previous integer to the current one

    # Print the final answer
    print(ans)

# Call the main function
main()

