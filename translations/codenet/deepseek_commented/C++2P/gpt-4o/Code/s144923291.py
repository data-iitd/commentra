# Import necessary libraries
import sys

# Define constants
intmax = sys.maxsize
lmax = sys.maxsize
uintmax = sys.maxsize
ulmax = sys.maxsize
llmax = sys.maxsize
ll = int

# Function for ceiling division
def cei(x, y):
    return -(-x // y)

# Function for greatest common divisor
def gcd(x, y):
    return gcd(y, x % y) if y else x

# Function for least common multiple
def lcm(x, y):
    return x // gcd(x, y) * y

# Function for power
def llpow(x, n):
    ans = 1
    for _ in range(n):
        ans *= x
    return ans

# Function for factorial
def fact(x):
    ans = 1
    for i in range(1, x + 1):
        ans *= i
    return ans

# Function for nCr
def ncr(n, r):
    return fact(n) // (fact(r) * fact(n - r))

# Function for nPr
def npr(n, r):
    return fact(n) // fact(n - r)

# Function for prime check
def prime(a):
    if a <= 1:
        return False
    for i in range(2, int(a**0.5) + 1):
        if a % i == 0:
            return False
    return True

# Function for Fibonacci sequence
def fib(x):
    fibo = [0] * (x + 10)
    fibo[0] = fibo[1] = fibo[2] = 1
    for i in range(3, x + 1):
        fibo[i] = fibo[i - 1] + fibo[i - 2]
    return fibo[x]

# Function for digit count
def dig(n):
    return len(str(n))

# Main function
if __name__ == "__main__":
    h, w = map(int, input().split())  # Read the dimensions of the grid
    s = "snuke"
    
    for i in range(h):  # Loop over each row
        for j in range(w):  # Loop over each column
            t = input().strip()  # Read a character array
            if t == s:  # Compare the character array with the pattern
                c = chr(ord('A') + j)  # Calculate the column letter
                print(f"{c}{i + 1}")  # Output the position in the grid
                sys.exit(0)  # Terminate the program

# <END-OF-CODE>
