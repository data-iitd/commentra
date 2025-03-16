# Include the standard input/output library

def main():
    sum = 0  # Declare and initialize the sum variable
    n = int(input())  # Read the number of inputs

    # Initialize min and max variables
    min = None
    max = None

    # Loop through each input
    for i in range(n):
        m = int(input())  # Read the current input
        sum += m  # Update the sum with the current input

        # Check if it's the first input to set initial min and max values
        if min is None or max is None:
            min = m
            max = m

        # Update the min value if the current input is smaller
        if min > m:
            min = m

        # Update the max value if the current input is larger
        if max < m:
            max = m

    # Output the minimum, maximum, and sum of the inputs
    print(min, max, sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
