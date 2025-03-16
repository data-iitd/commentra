import sys

# Define constants for maximum sizes and array size for dynamic programming
N_MAX = 100
P_MAX = 100
DP_ARRAY_SIZE = N_MAX * P_MAX // 32 + 1

# Define macros for common operations
def MIN(a, b):
    return a if a < b else b

def MAX(a, b):
    return a if a > b else b

def ABS(a):
    return -a if a < 0 else a

def ABSS(a, b):
    return a - b if a > b else b - a

# Function to find the last occurrence of a substring within a string
def strrstr(string, pattern):
    offset = 0
    lastP = None

    while True:
        search_result = string.find(pattern, offset)
        if search_result == -1 or string[offset] == '\0':
            break
        lastP = search_result
        offset += 1

    return lastP

# Comparison function for sort, comparing two size_t values
def compare_f(a, b):
    return -1 if a < b else 1

# Function to calculate combinations C(n, r)
def comb(n, r):
    result = 1

    # Calculate the combination using the formula
    for i in range(r):
        result *= n - i
        result //= i + 1

    return result

# Function to compute the greatest common divisor (GCD) of two numbers
def gcd(m, n):
    while m % n != 0:
        temp = n
        n = m % n
        m = temp

    return n

# Main function to execute the program
def main():
    pattern_base = "keyence"
    top = [0] * 8
    bottom = [0] * 8
    S = [0] * 101

    # Read the input string
    S = input()

    length = len(S)
    found = False

    # Loop through each possible split point in the pattern
    for offset in range(len(pattern_base)):
        # Split the pattern into top and bottom parts
        top[:offset] = pattern_base[:offset]
        top[offset] = '\0'
        bottom[:] = pattern_base[offset:]
        bottom[len(pattern_base) - offset] = '\0'

        # Search for the top part in the input string
        top_search = S.find(top)
        if top_search != -1:
            # Search for the bottom part after the found top part
            bottom_search = strrstr(S[top_search + offset:], bottom)
            if bottom_search != -1:
                sep_count = 0

                # Count the number of separators between top and bottom parts
                if top_search != 0:
                    sep_count += 1
                if top_search + offset != bottom_search:
                    sep_count += 1
                if bottom_search + len(bottom) != length:
                    sep_count += 1

                # Check if the number of separators is less than or equal to 1
                if sep_count <= 1:
                    found = True
                    break

    # Output the result based on whether the pattern was found
    print("YES" if found else "NO")

if __name__ == "__main__":
    main()
