import sys

MAX_N = 2000001
MAX_Ai = 10001
STR_SIZE = 10000010

def get_num():
    global p
    n = 0
    while p < len(str) and str[p].isdigit():
        n = n * 10 + int(str[p])  # Convert character to integer
        p += 1
    p += 1  # Move past the space or newline
    return n

def put_num(n):
    global p
    if n < 10:
        str_list.append(chr(ord('0') + n))  # Write single digit number
        return
    d = n // 10
    if d:
        put_num(d)  # Recursively write higher digits
    str_list.append(chr(ord('0') + (n - (d * 10))))  # Write the last digit

def counting_sort(A, B, k, length):
    C = [0] * MAX_Ai  # Initialize count array
    for j in range(1, length + 1):
        C[A[j]] += 1  # Count occurrences of each element
    for i in range(1, k + 1):
        C[i] += C[i - 1]  # Calculate cumulative count
    for j in range(length, 0, -1):
        B[C[A[j]]] = A[j]  # Place elements in sorted order
        C[A[j]] -= 1  # Decrement count for the element

# Main function
if __name__ == "__main__":
    str = sys.stdin.read()  # Read input into the buffer
    p = 0
    n = get_num()  # Get the number of elements
    A = [0] * MAX_N  # Input array
    B = [0] * MAX_N  # Output array
    for i in range(1, n + 1):
        A[i] = get_num()  # Read each element into the array A

    counting_sort(A, B, MAX_Ai, n)  # Sort the array A using Counting Sort

    str_list = []  # Buffer to write output
    for i in range(1, n):
        put_num(B[i])  # Write each sorted element
        str_list.append(' ')  # Write a space between elements
    put_num(B[n])  # Write the last element without a space

    print(''.join(str_list))  # Output the sorted string

# <END-OF-CODE>
