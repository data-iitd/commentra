# Python implementation of the provided C code

# Macro to put a character into the output string and increment the pointer
def put_char(c, p, str):
    str[p] = chr(c)
    return p + 1

# Function prototypes
def get_num(p, str):
    n = 0
    while '0' <= str[p] <= '9':
        n = n * 10 + (ord(str[p]) - ord('0'))
        p += 1
    p += 1  # Skip the non-digit character (likely a space or newline)
    return n, p

def put_num(n, p, str):
    if n < 10:
        p = put_char(ord('0') + n, p, str)
        return p
    d = n // 10
    if d:
        p = put_num(d, p, str)
    p = put_char(ord('0') + (n - (d * 10)), p, str)
    return p

def counting_sort(A, B, k, len, str):
    C = [0] * (k + 1)
    p = 0
    # Count occurrences of each number in A
    for j in range(1, len + 1):
        C[A[j]] += 1
    # Update count array to hold the position of each number
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    # Build the output array B using the count array
    for j in range(len, 0, -1):
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1
    return B

# Main function
def main():
    MAX_N = 2000001
    MAX_Ai = 10001
    STR_SIZE = 10000010

    # Global arrays for input and output
    A = [0] * (MAX_N + 1)
    B = [0] * (MAX_N + 1)
    str = [''] * STR_SIZE
    p = 0

    # Read the entire input into the string
    str = list(input())
    str.append('\0')  # Null-terminate the input string for simplicity

    # Get the number of elements from the input
    n, p = get_num(p, str)

    # Read each number into the array A
    for i in range(1, n + 1):
        A[i], p = get_num(p, str)

    # Perform counting sort on the array A and store the result in B
    B = counting_sort(A, B, MAX_Ai, n, str)

    # Reset the pointer to the start of the output string
    p = 0
    n -= 1  # Adjust n for zero-based indexing

    # Write the sorted numbers to the output string
    for i in range(1, n + 1):
        p = put_num(B[i], p, str)
        p = put_char(ord(' '), p, str)  # Append a space after each number

    p = put_num(B[n + 1], p, str)  # Append the last number without a trailing space
    p = put_char(ord('\0'), p, str)  # Null-terminate the output string

    # Output the final result
    print(''.join(str))

if __name__ == "__main__":
    main()
