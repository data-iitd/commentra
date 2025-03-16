import math  # Importing math for handling mathematical operations
from sys import stdin  # Importing stdin for reading input

def main():
    input = stdin.read
    data = input().split()  # Reading all input at once and splitting into a list
    n = int(data[0])  # Reading the first integer
    m = int(data[1])  # Reading the second integer
    gcd = math.gcd(n, m)  # Calculating the GCD of n and m
    s = data[2]  # Reading the first string
    t = data[3]  # Reading the second string

    # Filtering the range of the GCD and checking character mismatches
    for k in range(gcd):
        if s[k * n // gcd] != t[k * m // gcd]:
            print(-1)  # If a mismatch is found, print -1 and exit
            return

    # If no mismatches are found, calculate and print the result
    result = (n * m) // gcd
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
