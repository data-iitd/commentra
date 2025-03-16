import sys, math, collections, heapq, itertools

# Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
def gcd(a, b):
    a, b = max(a, b), min(a, b)
    while a % b > 0:
        a, b = b, a % b
    return b

# Main function to solve the problem
def solve():
    s = input()  # Read input string
    t = ""  # Initialize an empty string to store processed characters
    i = 0  # Initialize index
    
    # Process the input string character by character
    while i < len(s):
        if s[i] == "A":
            t += "A"
            i += 1
        elif s[i] == "B":
            if i < len(s) - 1:
                if s[i + 1] == "C":
                    t += "D"
                    i += 2
                else:
                    t += "X"
                    i += 1
            else:
                t += "X"
                i += 1
        else:
            t += "X"
            i += 1
    
    total = 0  # Initialize total count
    numA = 0  # Initialize count of 'A' characters
    
    # Count the number of 'A' characters before each 'X' in the processed string
    for i in range(len(t)):
        if t[i] == "X":
            numA = 0
        else:
            if t[i] == "A":
                numA += 1
            else:
                total += numA
    
    print(total)  # Print the total count
    
    # Define constants for infinity and modulo
    INF = 10 ** 25
    mod = 7 + 10 ** 9
    
    return 0

# Check if the script is being run as the main module
if __name__ == "__main__":
    solve()
