import sys

# Constants for maximum sizes
MAX_N = 2000001  # Maximum number of elements
MAX_Ai = 10001   # Maximum value of elements

# Function to read an integer from the input string
def get_num(input_str, index):
    n = 0  # Variable to store the number
    while index < len(input_str) and input_str[index].isdigit():
        n = n * 10 + int(input_str[index])  # Build the number
        index += 1  # Move to the next character
    return n, index + 1  # Return the read number and the next index

# Function to write an integer to the output list
def put_num(n, output):
    if n < 10:
        output.append(str(n))  # Convert to string and append
        return
    put_num(n // 10, output)  # Recursively write the digits of the number
    output.append(str(n % 10))  # Append the last digit

# Counting sort algorithm implementation
def counting_sort(A, len_A):
    C = [0] * (MAX_Ai)  # Count array initialized to zero
    B = [0] * len_A  # Output array

    # Count occurrences of each number in A
    for j in range(len_A):
        C[A[j]] += 1  # Increment count for each number

    # Update count array to hold the position of each number
    for i in range(1, MAX_Ai):
        C[i] += C[i - 1]  # C[i] now contains the position

    # Build the output array B using the count array
    for j in range(len_A - 1, -1, -1):
        B[C[A[j]] - 1] = A[j]  # Place the number in the correct position
        C[A[j]] -= 1  # Decrement the count for the number

    return B

def main():
    input_str = sys.stdin.read()  # Read the entire input
    index = 0  # Initialize index for reading numbers

    # Get the number of elements from the input
    n, index = get_num(input_str, index)
    A = []

    # Read each number into the array A
    for _ in range(n):
        num, index = get_num(input_str, index)
        A.append(num)

    # Perform counting sort on the array A
    B = counting_sort(A, n)

    # Prepare the output string
    output = []
    for i in range(n):
        put_num(B[i], output)  # Convert number to string and append
        if i < n - 1:
            output.append(' ')  # Append a space after each number

    # Output the final result
    print(''.join(output))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
