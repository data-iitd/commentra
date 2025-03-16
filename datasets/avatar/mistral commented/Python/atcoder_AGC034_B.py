# Importing necessary libraries
import sys, math, collections, heapq, itertools

# Function to find the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    # Making 'a' greater than 'b'
    a, b = max(a, b), min(a, b)
    
    # Finding the GCD using Euclidean algorithm
    while a % b > 0:
        a, b = b, a % b
    
    # Returning the GCD
    return b

# Function to solve the problem
def solve():
    # Reading the input string from standard input
    s = input()
    
    # Initializing an empty string 't' to store the output string
    t = ""
    
    # Iterating through each character in the input string 's'
    i = 0
    while i < len(s):
        # If the current character is 'A', append 'A' to 't' and move to the next character
        if s[i] == "A":
            t += "A"
            i += 1
        # If the current character is 'B', check if the next character is 'C'. If yes, append 'D' to 't' and move to the next character (two steps ahead). If no, append 'X' to 't' and move to the next character
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
        # If the current character is not 'A' or 'B', append 'X' to 't' and move to the next character
        else:
            t += "X"
            i += 1
    
    # Initializing variables 'total' and 'numA' to 0
    total = 0
    numA = 0
    
    # Iterating through each character in the output string 't'
    for i in range(len(t)):
        # If the current character is 'X', reset 'numA' to 0
        if t[i] == "X":
            numA = 0
        # If the current character is 'A', increment 'numA' by 1
        elif t[i] == "A":
            numA += 1
        # Adding the product of the number of 'A's in the current segment and the previous segment to 'total'
        total += numA
    
    # Printing the final answer
    print(total)

# Starting the program if the script is run directly
if __name__ == "__main__":
    # Calling the 'solve' function
    solve()
