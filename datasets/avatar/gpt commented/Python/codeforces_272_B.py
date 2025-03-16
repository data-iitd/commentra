def main():
    # Read input from the user (not stored, just consumed)
    input()
    # Process the input sequence and return the number of pairs with common factors
    return nPairsWithCommonFX(map(int, input().split()))

def nPairsWithCommonFX(sequence):
    # Initialize a dictionary to store values based on their computed factor
    storage = {}
    # List to keep track of unique factors
    FXs = []
    
    # Iterate through each value in the input sequence
    for value in sequence:
        # Compute the factor for the current value
        y = f(value)
        # If the factor is not already in storage, add it
        if y not in storage:
            storage[y] = [value]  # Store the value under its factor
            FXs.append(y)         # Keep track of the unique factor
        else:
            # If the factor already exists, append the value to the existing list
            storage[y].append(value)
    
    # Calculate the total number of pairs with common factors
    # The formula counts pairs and subtracts the number of single occurrences
    return (sum(len(storage[y]) * len(storage[y]) for y in FXs) - sum(len(storage[y]) for y in FXs)) // 2

def f(n):
    # Initialize the factor count
    y = 1
    # Loop until n is reduced to 1
    while n != 1:
        # If n is odd, increment the factor count
        if n % 2:
            y += 1
        # Divide n by 2 to reduce it
        n //= 2
    # Return the total count of factors
    return y

if __name__ == '__main__':
    # Execute the main function and print the result
    print(main())
