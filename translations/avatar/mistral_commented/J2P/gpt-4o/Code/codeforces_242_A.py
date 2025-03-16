# Import the necessary module for reading input
import sys

# Create a function to encapsulate the main logic
def main():
    # Read four integers from the console
    x, y, a, b = map(int, sys.stdin.readline().split())

    # Initialize a counter variable
    count = 0

    # Find the number of pairs (i, j) that satisfy the condition i < j
    for i in range(a, x + 1):
        for j in range(b, y + 1):
            # If i is less than j, continue to the next iteration of the inner loop
            if i <= j:
                continue

            # Increment the counter if the condition is satisfied
            count += 1

    # Print the result
    print(count)

    # Print all pairs (i, j) that satisfy the condition i < j
    for i in range(a, x + 1):
        for j in range(b, y + 1):
            # If i is less than j, print the pair
            if i <= j:
                print(i, j)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
