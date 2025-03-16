#include <stdio.h>

# Function to return the minimum of two integers
def min(a, b):
    if a <= b:
        return a
    return b

# Function to process the chain of colors and return the count of remaining colors
def Chain(b, n):
    a = [0] * 10000 # Array to hold the current state of colors
    count = 0 # To count the number of consecutive colors
    color = 0 # To store the current color being processed

    # Copy input array b to array a
    for i in range(n):
        a[i] = b[i]

    # Loop through the array to find sequences of four identical colors
    for i in range(n - 4):
        # Check if there are four consecutive identical colors
        if a[i] != 0 and a[i] == a[i + 1] and a[i] == a[i + 2] and a[i] == a[i + 3]:
            # Initialize count and set the current color
            count = 0
            color = a[i]

            # Set the found colors to zero and count them
            for j in range(i, n):
                if a[j] == color:
                    a[j] = 0 # Remove the color by setting it to zero
                    count += 1 # Increment the count of removed colors

            # Shift the remaining colors to fill the gap left by removed colors
            for j in range(i, n - count):
                a[j] = a[j + count]
                a[j + count] = 0 # Set the shifted out colors to zero

            # Reset the index to start checking from the beginning
            i = 0

    # Count the number of remaining colors in the array
    count = 0
    while a[count] != 0:
        count += 1

    # Check if there are exactly four of the same color left at the start
    if count == 4 and a[0] == a[1] and a[0] == a[2] and a[0] == a[3]:
        return 0 # Return 0 if four identical colors remain

    return count # Return the count of remaining colors

# Main function to execute the program
def main():
    n = 0 # Number of colors
    i, j = 0, 0
    a = [0] * 10000 # Array to hold the colors
    ans = 0 # Variable to hold the answer
    color = 0 # Variable to store the current color being processed

    # Infinite loop to process multiple test cases
    while True:
        # Initialize the array to zero
        for i in range(10000):
            a[i] = 0

        # Read the number of colors
        n = int(input())
        if n == 0:
            break # Exit the loop if n is 0
        ans = n # Initialize ans with the number of colors

        # Read the colors into the array
        for i in range(n):
            a[i] = int(input())

        # Check for groups of four colors to replace
        for i in range(n - 4):
            count = [0, 0, 0] # Array to count occurrences of colors

            # Count occurrences of colors in the current window of four
            for j in range(i, i + 4):
                if a[j] - 1 >= 0:
                    count[a[j] - 1] += 1

            color = 0 # Reset color
            # Determine if any color appears at least three times
            for j in range(3):
                if count[j] >= 3:
                    color = j + 1 # Set the color to replace
                    break

            # If a color is found to replace, perform the replacement
            if color != 0:
                for j in range(i, i + 4):
                    buf = a[j] # Temporary variable to hold the current color
                    a[j] = color # Replace with the new color
                    ans = min(ans, Chain(a, n)) # Calculate the new answer
                    a[j] = buf # Restore the original color

        # Print the final answer for the current test case
        print(ans)

# Main function to execute the program
if __name__ == "__main__":
    main()

