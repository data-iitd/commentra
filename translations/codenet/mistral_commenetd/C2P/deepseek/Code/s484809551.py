import sys

# Define constants
N_MAX = 100
P_MAX = 100
DP_ARRAY_SIZE = (N_MAX * P_MAX // 32 + 1)

# Define helper functions
def min(a, b):
    return a if a < b else b

def max(a, b):
    return a if a > b else b

def abs(a):
    return -a if a < 0 else a

def abs_diff(a, b):
    return a - b if a > b else b - a

# Function to find the last occurrence of a substring in a string
def rfind_substring(string, pattern):
    offset = 0
    last_p = None

    while True:
        search_result = string.find(pattern, offset)
        if search_result == -1 or string[offset] == '\0':
            break
        last_p = search_result
        offset += 1

    return last_p

# Function to compare two pointers for sort
def compare_f(a, b):
    return -1 if a < b else 1

# Function to calculate the number of combinations of n items taken r at a time
def comb(n, r):
    result = 1

    for i in range(r):
        result *= n - i
        result //= i + 1

    return result

# Function to find the greatest common divisor of two numbers
def gcd(m, n):
    while m % n != 0:
        temp = n
        n = m % n
        m = temp

    return n

# Main function
def main():
    # Define pattern base string
    pattern_base = "keyence"
    top = [None] * 8
    bottom = [None] * 8
    s = [None] * 101

    # Read input string from standard input
    s_input = input()
    s_input = s_input.strip()

    # Calculate length of input string
    length = len(s_input)
    found = False

    # Loop through each character in pattern base string
    for offset in range(len(pattern_base)):
        # Copy substring up to current character to top variable
        top[:offset] = s_input[:offset]
        top[offset] = '\0'

        # Copy substring from current character to end of pattern base string to bottom variable
        bottom[:len(pattern_base) - offset] = s_input[offset:]
        bottom[len(pattern_base) - offset] = '\0'

        # Search for top substring in input string
        top_search = s_input.find(top)

        # If top substring is found
        if top_search != -1:
            # Search for bottom substring after top substring in input string
            bottom_search = rfind_substring(s_input[top_search + offset:], bottom)

            # If bottom substring is found
            if bottom_search != -1:
                # Calculate number of separators between top and bottom substrings
                sep_count = 0

                # If topSearch is not the first occurrence of top substring in input string
                if top_search != 0:
                    sep_count += 1

                # If topSearch is not the same as bottomSearch
                if top_search + offset != bottom_search:
                    sep_count += 1

                # If bottomSearch is not the last character in input string
                if bottom_search + len(bottom) < length:
                    sep_count += 1

                # If number of separators is less than or equal to 1
                if sep_count <= 1:
                    found = True
                    break

    # Print output based on whether pattern is found or not
    print("YES" if found else "NO")

if __name__ == "__main__":
    main()
