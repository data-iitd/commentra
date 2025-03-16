def main():
    # Infinite loop to continuously read input until termination condition is met
    while True:
        # Read two integers from the standard input
        n, x = map(int, input().split())

        # Check for the termination condition: both n and x are zero
        if n == 0 and x == 0:
            break  # Exit the loop if the termination condition is met

        # Initialize a counter to keep track of the number of valid combinations
        c = 0

        # Iterate through all possible combinations of three distinct integers
        for i in range(1, n - 1):  # First integer
            for j in range(i + 1, n):  # Second integer
                for k in range(j + 1, n + 1):  # Third integer
                    # Check if the sum of the three integers equals x
                    if i + j + k == x:
                        c += 1  # Increment the counter if the condition is satisfied

        # Output the count of valid combinations for the current input
        print(c)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
