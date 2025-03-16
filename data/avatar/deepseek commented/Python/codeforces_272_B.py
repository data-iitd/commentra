def main():
    # Take input from the user
    input()
    # Process the input and call nPairsWithCommonFX with the processed input
    return nPairsWithCommonFX(map(int, input().split()))

def nPairsWithCommonFX(sequence):
    # Initialize a dictionary to store values grouped by their computed property
    storage = {}
    # List to store the computed property values
    FXs = []
    for value in sequence:
        # Compute the property for the current value
        y = f(value)
        # If the property is not already in storage, add it with the current value
        if y not in storage:
            storage[y] = [value]
            FXs.append(y)
        else:
            # Otherwise, append the current value to the list of values for this property
            storage[y].append(value)
    # Calculate the number of pairs with common factor greater than 1
    return (sum(len(storage[y]) * len(storage[y]) for y in FXs) - sum(len(storage[y]) for y in FXs)) // 2

def f(n):
    # Initialize y to 1, which will be the result for the property of n
    y = 1
    while n != 1:
        if n % 2:
            y += 1
        n //= 2
    return y

if __name__ == '__main__':
    # Print the result of the main function
    print(main())
