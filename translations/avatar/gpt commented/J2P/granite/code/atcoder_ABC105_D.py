
import sys

def main():
    # Set up input and output streams
    input = sys.stdin
    output = sys.stdout

    # Read the number of elements and the modulus value
    n, m = map(int, input.readline().split())

    # Read the array of integers
    a = list(map(int, input.readline().split()))

    # Initialize a HashMap to store counts of remainders
    dp = {}
    ans = 0  # Variable to store the final answer
    base = 0  # Variable to track the base remainder

    # Iterate through the array to calculate the answer
    for i in range(n):
        # Update the base remainder
        base = (base - a[i] % m + m) % m

        # Merge the current remainder into the HashMap
        dp[base] = dp.get(base, 0) + 1

        # Add the count of occurrences of the current base remainder to the answer
        ans += dp.get(base - a[i], 0)

    # Output the final answer
    output.write(str(ans) + '\n')

if __name__ == '__main__':
    main()

