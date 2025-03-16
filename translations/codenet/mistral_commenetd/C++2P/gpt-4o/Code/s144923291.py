# Import necessary libraries
import sys

# Define constants for maximum integer values
intmax = sys.maxsize
lmax = sys.maxsize
uintmax = sys.maxsize
ulmax = sys.maxsize
llmax = sys.maxsize

# Function for ceiling division
def cei(x, y):
    return (x + y - 1) // y

# Function for finding greatest common divisor
def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

# Function for finding least common multiple
def lcm(x, y):
    return x // gcd(x, y) * y

# Function for exponentiation
def llpow(x, n):
    ans = 1
    for _ in range(n):
        ans *= x
    return ans

# Function for factorial calculation
def fact(x):
    ans = 1
    for i in range(1, x + 1):
        ans *= i
    return ans

# Function for calculating nCr
def ncr(n, r):
    return fact(n) // (fact(r) * fact(n - r))

# Function for calculating nPr
def npr(n, r):
    return fact(n) // fact(n - r)

# Function for prime number check
def prime(a):
    if a <= 1:
        return False
    for i in range(2, int(a**0.5) + 1):
        if a % i == 0:
            return False
    return True

# Function for generating Fibonacci sequence
def fib(x):
    fibo = [0] * (x + 1)
    fibo[0] = fibo[1] = fibo[2] = 1
    for i in range(3, x + 1):
        fibo[i] = fibo[i - 1] + fibo[i - 2]
    return fibo[x]

# Function for finding number of digits
def dig(n):
    return len(str(n))

# Main function
def main():
    h, w = map(int, input().split())  # Read height and width from standard input
    s = "snuke"  # Initialize the pattern string
    for i in range(h):  # Iterate through each row of the grid
        t = input().strip()  # Read a character from standard input
        if t == s:  # Check if current character matches the pattern 'snuke'
            c = chr(ord('A') + i)  # Calculate the row index 'i' and convert it to ASCII character
            print(f"{c}{i + 1}")  # Print the character and its row number to standard output
            return  # Exit the program if a match is found

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
