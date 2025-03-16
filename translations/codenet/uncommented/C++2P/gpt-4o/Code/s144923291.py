# Import necessary libraries
import sys

# Define constants
intmax = sys.maxsize
lmax = sys.maxsize
uintmax = sys.maxsize
ulmax = sys.maxsize
llmax = sys.maxsize

# Function to read input
def sc():
    return input().strip()

# Function to print output
def pr(a):
    print(a)

# Function to check if a number is prime
def prime(a):
    if a <= 1:
        return False
    for i in range(2, int(a**0.5) + 1):
        if a % i == 0:
            return False
    return True

# Main function
def main():
    h, w = map(int, sc().split())
    s = "snuke"
    
    for i in range(h):
        for j in range(w):
            t = sc()
            if t == s:
                c = chr(ord('A') + j)
                pr(f"{c}{i + 1}")
                return

# Execute main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
