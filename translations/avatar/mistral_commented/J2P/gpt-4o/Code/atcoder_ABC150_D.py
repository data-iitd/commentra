import sys
from math import gcd

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Reading the first integer n from the standard input
    m = int(data[1])  # Reading the second integer m from the standard input
    a = [int(data[i + 2]) // 2 for i in range(n)]  # Initializing the array a with input values divided by 2

    lcd = 1  # Declaring and initializing a variable lcm to store the least common multiple

    # Finding the least common multiple of all array elements
    for i in range(n):
        current_gcd = gcd(lcd, a[i])  # Finding the greatest common divisor of lcm and the current array element
        lcd = lcd * a[i] // current_gcd  # Updating the value of lcm

        # Checking if lcm is greater than m
        if lcd > m:
            print(0)  # If true, printing 0 and returning from the method
            return

    # Checking if any array element is a factor of lcm
    for i in range(n):
        if (lcd // a[i]) % 2 == 0:  # Checking if the remainder of lcm divided by the current array element is 0 and even
            print(0)  # If true, printing 0 and returning from the method
            return

    # Printing the result
    print((m // lcd + 1) // 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
