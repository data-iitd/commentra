# Import necessary libraries
import sys

def main():
    # Read the number of values to be processed
    N = int(sys.stdin.readline().strip())

    # Initialize a list to hold the float values
    values = []

    # Read N float values from standard input
    for _ in range(N):
        values.append(float(sys.stdin.readline().strip()))

    # Sort the list of float values in ascending order
    values.sort()

    # Variable to hold the generated average value
    generated = 0.0

    # Calculate the average of each pair of adjacent values
    for i in range(N - 1):
        generated = (values[i] + values[i + 1]) / 2
        # Update the next value in the list with the generated average
        values[i + 1] = generated

    # Print the last generated average value
    print(generated)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
