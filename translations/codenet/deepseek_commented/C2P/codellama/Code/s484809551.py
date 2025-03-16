#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

# Define constants for maximum sizes and array size for dynamic programming
N_MAX = 100
P_MAX = 100
DP_ARRAY_SIZE = N_MAX * P_MAX / 32 + 1

# Define macros for common operations
MIN = lambda a, b: a if a < b else b
MAX = lambda a, b: a if a > b else b
ABS = lambda a: -a if a < 0 else a
ABSS = lambda a, b: a - b if a > b else b

# Function to find the last occurrence of a substring within a string
def strrstr(string, pattern):
    offset = 0
    lastP = None

    searchResult = None
    # Loop to find the last occurrence of the pattern
    while (searchResult := strstr(string[offset:], pattern)) != None and string[offset] != '\0':
        lastP = searchResult # Update last found position
        offset += 1 # Move offset to search for further occurrences

    return lastP # Return the last found position

# Comparison function for qsort, comparing two size_t values
def compare_f(a, b):
    return a < b ? -1 : 1 # Return comparison result

# Function to calculate combinations C(n, r)
def comb(n, r):
    result = 1

    # Calculate the combination using the formula
    for i in range(r):
        result *= n - i # Multiply by decreasing values of n
        result //= i + 1 # Divide by increasing values of r

    return result # Return the result

# Function to compute the greatest common divisor (GCD) of two numbers
def gcd(m, n):
    temp = 0

    # Euclidean algorithm to find GCD
    while m % n != 0:
        temp = n
        n = m % n # Update n to the remainder
        m = temp # Update m to the previous n

    return n # Return the GCD

# Main function to execute the program
def main():
    patternBase = "keyence" # Define the pattern to search for
    top = [0] * 8 # Buffers to hold split parts of the pattern
    bottom = [0] * 8
    S = [0] * 101 # Buffer to hold the input string

    # Read the input string
    S = input()

    len = len(S) # Get the length of the input string
    found = False # Flag to indicate if the pattern is found

    # Loop through each possible split point in the pattern
    for offset in range(len(patternBase)):
        # Split the pattern into top and bottom parts
        top = patternBase[:offset]
        bottom = patternBase[offset:]

        # Search for the top part in the input string
        topSearch = strstr(S, top)
        if topSearch != None:
            # Search for the bottom part after the found top part
            bottomSearch = strrstr(topSearch[offset:], bottom)
            if bottomSearch != None:
                sepCount = 0 # Counter for separators

                # Count the number of separators between top and bottom parts
                if topSearch != S:
                    sepCount += 1 # Increment if there's text before the top part
                if topSearch[offset:] != bottomSearch:
                    sepCount += 1 # Increment if there's text between top and bottom parts
                if bottomSearch[len(bottom)] != '\0':
                    sepCount += 1 # Increment if there's text after the bottom part

                # Check if the number of separators is less than or equal to 1
                if sepCount <= 1:
                    found = True # Set found flag to true
                    break # Exit the loop as the pattern is found

    # Output the result based on whether the pattern was found
    print("YES" if found else "NO")

    return 0 # Return success


# END-OF-CODE
