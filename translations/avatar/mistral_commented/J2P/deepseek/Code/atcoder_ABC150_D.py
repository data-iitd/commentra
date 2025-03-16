import sys
from math import gcd

def main():
    # Reading the input values
    n, m = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))

    # Initializing the array a with input values
    a = [x // 2 for x in a]

    # Finding the least common multiple of all array elements
    lcd = 1
    for i in range(n):
        g = gcd(lcd, a[i])
        lcd = lcd * a[i] // g

        # Checking if lcm is greater than m
        if lcd > m:
            print(0)
            return

    # Checking if any array element is a factor of lcm
    for i in range(n):
        if (lcd // a[i]) % 2 == 0:
            print(0)
            return

    # Printing the result
    print((m // lcd + 1) // 2)

if __name__ == "__main__":
    main()

