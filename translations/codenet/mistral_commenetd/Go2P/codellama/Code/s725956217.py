
# Package main is the entry point of the program
import sys

# Function out is used for printing output to the console
def out(x):
    print(x)

# Function getInt is used for reading an integer value from the standard input
def getInt():
    return int(sys.stdin.readline())

# Function getString is used for reading a string value from the standard input
def getString():
    return sys.stdin.readline().strip()

# Function max returns the maximum value between two integers
def max(a, b):
    if a > b:
        return a
    else:
        return b

# Function min returns the minimum value between two integers
def min(a, b):
    if a < b:
        return a
    else:
        return b

# Function asub returns the absolute difference between two integers
def asub(a, b):
    if a > b:
        return a - b
    else:
        return b - a

# Function abs returns the absolute value of an integer
def abs(a):
    if a >= 0:
        return a
    else:
        return -a

# Function lowerBound returns the index of the first element in the slice that is greater than or equal to the given value
def lowerBound(a, x):
    for i in range(len(a)):
        if a[i] >= x:
            return i
    return len(a)

# Function upperBound returns the index of the first element in the slice that is greater than the given value
def upperBound(a, x):
    for i in range(len(a)):
        if a[i] > x:
            return i
    return len(a)

# Type shop represents a data structure for storing two integers
class shop:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Type Datas is a slice of shop data structures
class Datas:
    def __init__(self, s):
        self.s = s

    def __len__(self):
        return len(self.s)

    def __getitem__(self, i):
        return self.s[i]

    def __setitem__(self, i, e):
        self.s[i] = e

    def __lt__(self, other):
        return self.s[0].a < other.s[0].a

# Main function is the entry point of the program
def main():
    # Read the number of shops N and the number of customers M from the standard input
    N, M = getInt(), getInt()
    # Initialize a slice of shop data structures named s with a length of N
    s = Datas([shop(getInt(), getInt()) for _ in range(N)])
    # Sort the slice in ascending order based on the 'a' field of each shop
    s.sort()

    # Initialize a variable named total to store the total capacity used by the shops
    total = 0
    # For each shop in the sorted slice
    for e in s.s:
        # Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
        n = min(e.b, M)
        # Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
        total += n * e.a
        # Decrease the maximum demand by the number of customers served by the shop
        M -= n
        # If the maximum demand becomes zero, break the loop
        if M == 0:
            break
    # Print the total capacity used by the shops
    out(total)

# END-OF-CODE
