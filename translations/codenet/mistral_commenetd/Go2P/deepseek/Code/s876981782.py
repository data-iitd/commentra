def main():
    # Read input: number of values
    N = int(input())

    # Read input: N float64 values
    values = list(map(float, input().split()))

    # Sort the list in ascending order
    values.sort()

    # Calculate the median value
    for i in range(N - 1):
        # Calculate the average of the current and next value
        generated = (values[i] + values[i + 1]) / 2

        # Update the next value with the calculated average
        values[i + 1] = generated

    # Print the calculated median value
    print(generated)

# Call the main function
main()
