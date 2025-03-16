# This is the main function that takes input and calls the helper function nPairsWithCommonFX
def main():
    # Read input from standard input
    input()

    # Call the helper function with the sequence obtained from input
    result = nPairsWithCommonFX(map(int, input().split()))

    # Print the result
    print(result)

# This function takes a sequence as input and returns the number of pairs with common FX
def nPairsWithCommonFX(sequence):
    # Initialize an empty dictionary to store FX values and their corresponding values
    storage = {}

    # Initialize an empty list to store unique FX values
    FXs = []

    # Iterate through each value in the sequence
    for value in sequence:
        # Compute the FX value for the current value
        fx = f(value)

        # If the FX value is not already in the dictionary, add it along with the value
        if fx not in storage:
            storage[fx] = [value]
            FXs.append(fx)

        # If the FX value is already in the dictionary, add the current value to the list of values for that FX
        else:
            storage[fx].append(value)

    # Calculate the result using the formula given in the problem statement
    result = (sum(len(storage[fx]) * len(storage[fx]) for fx in FXs) - sum(len(storage[fx]) for fx in FXs)) // 2

    # Return the result
    return result

# This function takes an integer as input and returns its FX value
def f(n):
    # Initialize a variable to store the FX value
    fx = 1

    # Perform bitwise operations until the number is reduced to 1
    while n != 1:
        # If the number is odd, increment the FX value
        if n % 2:
            fx += 1

        # Divide the number by 2 to reduce it further
        n //= 2

    # Return the final FX value
    return fx

# Run the main function if the script is executed directly
if __name__ == '__main__':
    # Call the main function and print the result
    print(main())
