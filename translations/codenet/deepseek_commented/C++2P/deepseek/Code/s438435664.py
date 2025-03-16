def gcd(x, y):
    if x < y:
        x, y = y, x
    while y > 0:
        r = x % y
        x = y
        y = r
    return x


def lcm(x, y):
    return x // gcd(x, y) * y


def kaijo(k):
    sum = 1
    for i in range(1, k + 1):
        sum *= i
        sum %= 1000000000 + 7
    return sum


def lmax(s, t):
    return s if s > t else t


def lmin(s, t):
    return s if s < t else t


def main():
    # Read two integers n and k
    n, k = map(int, input().split())
    sum = 0

    # Iterate over possible values of b
    for b in range(1, n + 1):
        # Calculate the count and remainder
        cnt = (n + 1) // b
        md = (n + 1) % b

        # Update the sum based on the conditions involving k
        sum += cnt * max((b - k), 0) + max((md - k), 0)

        # Adjust the sum if k is 0
        if k == 0:
            sum -= 1

    # Print the computed sum
    print(sum)


main()
