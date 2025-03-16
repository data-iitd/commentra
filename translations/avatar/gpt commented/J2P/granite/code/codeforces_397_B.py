
import sys
import math

def main():
    # Initialize input and output streams
    input = sys.stdin
    output = sys.stdout

    # Read the number of test cases
    t = int(input.readline())

    # Process each test case
    for _ in range(t):
        # Read input values for each test case
        n, a, b = map(int, input.readline().split())

        # Check if n is less than a, if so, output "No"
        if n < a:
            output.write("No\n")
            continue

        # If a equals b, check if n is a multiple of a
        if a == b:
            if n % a == 0:
                output.write("Yes\n")
            else:
                output.write("No\n")
            continue

        # Calculate the maximum number of a's that can fit into b
        x = b // (b - a)

        # If n is greater than x * a, output "Yes"
        if n > x * a:
            output.write("Yes\n")
            continue

        # Binary search to find the largest mid such that mid * a < n
        low = 1
        high = x + 1
        ans = 1
        while low <= high:
            mid = (low + high) // 2

            # Adjust the search range based on the condition
            if mid * a < n:
                low = mid + 1
            else:
                ans = mid
                high = mid - 1

        # Check the final conditions to determine output
        if n > (ans - 1) * b and n < ans * a:
            output.write("No\n")
        else:
            output.write("Yes\n")

if __name__ == "__main__":
    main()

