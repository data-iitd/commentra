def gcd(x, y):
    # Ensure x is greater than or equal to y
    if x < y:
        x, y = y, x
    # Apply the Euclidean algorithm to find GCD
    while y > 0:
        r = x % y
        x = y
        y = r
    return x  # Return the GCD


def lcm(x, y):
    return x // gcd(x, y) * y  # LCM formula using GCD


def kaijo(k):
    sum = 1
    # Calculate factorial iteratively
    for i in range(1, k + 1):
        sum *= i  # Multiply current sum by i
        sum %= 1000000007  # Take modulo to prevent overflow
    return sum  # Return the factorial


def lmax(s, t):
    if s > t:
        return s  # Return s if it is greater
    else:
        return t  # Otherwise return t


def lmin(s, t):
    if s < t:
        return s  # Return s if it is smaller
    else:
        return t  # Otherwise return t


# Main function to execute the program
def main():
    n, k = map(int, input().split())
    sum = 0  # Initialize sum to zero

    # Loop through each integer b from 1 to n
    for b in range(1, n + 1):
        # Calculate the count of multiples of b in the range [1, n]
        cnt = (n + 1) // b
        # Calculate the remainder when n + 1 is divided by b
        md = (n + 1) % b
        # Update the sum based on the count and the maximum values
        sum += cnt * max((b - k), 0) + max((md - k), 0)
        # Adjust the sum if k is zero
        if k == 0:
            sum -= 1

    # Output the final computed sum
    print(sum)


main()
