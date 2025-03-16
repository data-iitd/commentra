def walk_on_multiplication_table(num):
    # Initialize the variable `div` to 0.
    # `div` will store the largest divisor of `num` that is less than `sqrt(num)`.
    div = 0

    # Start the loop from the integer value of the square root of `num` down to 2.
    for i in range(int(math.sqrt(num)), 1, -1):
        # Check if `num` is divisible by the current value of `i`.
        if num % i == 0:
            # If `num` is divisible by `i`, set `div` to `i` and break out of the loop.
            div = i
            break

    # Check if `div` is still 0, which means no divisor was found.
    if div == 0:
        # If no divisor was found, return `num - 1`.
        return num - 1

    # Otherwise, return the sum of the divisor and the quotient of `num` divided by the divisor, minus 2.
    return div + num // div - 2


# The main function reads an integer from the standard input.
# It then prints the result of calling `walk_on_multiplication_table` with the input integer.
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    a = int(input().strip())
    print(walk_on_multiplication_table(a))
