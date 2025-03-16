import sys
import math

def main():
    n = int(input())  # Read the first integer n
    m = int(input())  # Read the second integer m
    a = []

    # Initialize array a with size n, where each element is half of the next input
    for _ in range(n):
        a.append(int(input()) // 2)

    lcd = 1

    # Calculate the least common multiple (LCM) of the elements in array a
    for i in range(n):
        gcd = get_gcd(lcd, a[i])
        lcd = lcd * a[i] // gcd
        if lcd > m:  # Check if LCM exceeds m
            print(0)
            return

    # Check if the LCM is even for any element in the array
    for i in range(n):
        if (lcd // a[i]) % 2 == 0:
            print(0)
            return

    # Calculate and print the number of integers up to m that are divisible by the LCM
    print((m // lcd + 1) // 2)

# Helper function to compute the greatest common divisor (GCD) of two numbers
def get_gcd(a, b):
    if b == 0:
        return a
    else:
        return get_gcd(b, a % b)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
