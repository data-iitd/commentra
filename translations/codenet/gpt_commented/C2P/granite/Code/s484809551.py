
import sys

# Define constants for maximum sizes and array size for dynamic programming
N_MAX = 100
P_MAX = 100
DP_ARRAY_SIZE = (N_MAX * P_MAX // 32) + 1

# Define macros for common operations
def MIN(a, b):
    return a if a < b else b

def MAX(a, b):
    return a if a > b else b

def ABS(a):
    return a if a >= 0 else -a

def ABSS(a, b):
    return ABS(a - b)

# Function to find the last occurrence of a substring within a string
def strrstr(string, pattern):
    offset = 0
    last_p = None

    search_result = None
    # Loop to find the last occurrence of the pattern
    while (search_result := string.find(pattern, offset))!= -1 and string[offset]!= '\0':
        last_p = search_result  # Update last found position
        offset += 1  # Move offset to search for further occurrences

    return last_p  # Return the last found position

# Comparison function for qsort, comparing two size_t values
def compare_f(a, b):
    return a < b

# Function to calculate combinations C(n, r)
def comb(n, r):
    result = 1

    # Calculate the combination using the formula
    for i in range(r):
        result *= (n - i)  # Multiply by decreasing values of n
        result //= (i + 1)  # Divide by increasing values of r

    return result  # Return the result

# Function to compute the greatest common divisor (GCD) of two numbers
def gcd(m, n):
    temp = 0

    # Euclidean algorithm to find GCD
    while m % n!= 0:
        temp = n
        n = m % n  # Update n to the remainder
        m = temp  # Update m to the previous n

    return n  # Return the GCD

# Main function to execute the program
def main():
    pattern_base = "keyence"  # Define the pattern to search for
    top = ""
    bottom = ""
    S = ""

    # Read the input string
    S = input()

    len_S = len(S)  # Get the length of the input string
    found = False  # Flag to indicate if the pattern is found

    # Loop through each possible split point in the pattern
    for offset in range(len(pattern_base)):
        # Split the pattern into top and bottom parts
        top = pattern_base[:offset]
        bottom = pattern_base[offset:]

        # Search for the top part in the input string
        top_search = S.find(top)
        if top_search!= -1:
            # Search for the bottom part after the found top part
            bottom_search = S.rfind(bottom, top_search + offset)
            if bottom_search!= -1:
                sep_count = 0  # Counter for separators

                # Count the number of separators between top and bottom parts
                if top_search!= 0:
                    sep_count += 1  # Increment if there's text before the top part
                if bottom_search!= top_search + offset:
                    sep_count += 1  # Increment if there's text between top and bottom parts
                if bottom_search + len(bottom)!= len_S:
                    sep_count += 1  # Increment if there's text after the bottom part

                # Check if the number of separators is less than or equal to 1
                if sep_count <= 1:
                    found = True  # Set found flag to true
                    break  # Exit the loop as the pattern is found

    # Output the result based on whether the pattern was found
    print("YES" if found else "NO")

if __name__ == "__main__":
    main()

Translate the above Python code to C and end with comment "