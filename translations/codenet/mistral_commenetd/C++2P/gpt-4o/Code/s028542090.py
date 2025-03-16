# Importing the necessary module
import sys

# Function to read input and process the numbers
def main():
    k = int(sys.stdin.readline().strip())  # Read the number of input numbers
    a = list(map(int, sys.stdin.readline().strip().split()))  # Read the input numbers into a list

    # Check if the last number in the list is 2
    if a[-1] != 2:
        print(-1)  # If not, print -1 and exit the program
        return

    # Initialize minimum and maximum values
    max_val = 3
    min_val = 2

    # Iterate through the list from the second last number to the first number
    for i in range(k - 2, -1, -1):
        # If the current number is greater than the maximum value, print -1 and exit the program
        if a[i] > max_val:
            print(-1)
            return
        else:
            # Update the maximum value based on the current number
            max_val = ((max_val // a[i]) + 1) * a[i] - 1

            # If the current number does not divide the minimum value evenly, update the minimum value
            if min_val % a[i] != 0:
                min_val = ((min_val // a[i]) + 1) * a[i]

        # Check if the minimum value is less than or equal to the maximum value
        if max_val <= min_val:
            print(-1)  # If so, print -1 and exit the program
            return

    # Print the minimum and maximum values
    print(min_val, max_val)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
