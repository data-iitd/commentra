import math

def main():
    # Create a Scanner object to read input from the user
    scan = Scanner(System.in)

    # Read three double values from the user: N, d, and x
    N = scan.nextDouble()
    d = scan.nextDouble()
    x = scan.nextDouble()

    # Initialize a variable to store the accumulated answer
    ans = 0.0

    # Loop until N is greater than 0.5
    while N > 0.5:
        # Calculate the current term to be added to the answer
        adnum = d + x * (N - 0.5)
        # Add the current term to the accumulated answer
        ans = ans + adnum

        # Update d using the formula provided
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
        # Update x using the formula provided
        x = (1.0 + (2.0 / N)) * x

        # Decrement N for the next iteration
        N = N - 1

    # Print the formatted result
    print(format(ans, '.20f'))

if __name__ == '__main__':
    main()

