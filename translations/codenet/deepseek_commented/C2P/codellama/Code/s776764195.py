#include <stdio.h>
  
#define PutChar(c) ; *p = (char)(c); ++p;
  
#define MAX_N (2000001)
#define MAX_Ai (10001)
#define STR_SIZE (10000010)
  
def getNum():
    n = 0
    while ((*p >= '0') and (*p <= '9')):
        n = n * 10 + (int)(*p - '0') # Convert character to integer
        ++p
    ++p # Move past the space or newline
    return n
  
def putNum(n):
    d = 0
    if (n < 10):
        PutChar('0' + n) # Write single digit number
        return
    d = n / 10
    if (d): putNum(d) # Recursively write higher digits
    PutChar('0' + (n - (d * 10))) # Write the last digit
  
def CountingSort(A, B, k, len):
    C = [0] * MAX_Ai # Initialize count array
    i = 0
    j = 0
    for j in range(1, len + 1):
        ++C[A[j]] # Count occurrences of each element
    for i in range(1, k + 1):
        C[i] += C[i - 1] # Calculate cumulative count
    for j in range(len, 0, -1):
        B[C[A[j]]] = A[j] # Place elements in sorted order
        --C[A[j]] # Decrement count for the element
  
str = '' # Buffer to read input
p = str # Pointer to traverse the buffer
  
n = getNum() # Get the number of elements
for i in range(1, n + 1):
    A[i] = getNum() # Read each element into the array A
  
CountingSort(A, B, MAX_Ai, n) # Sort the array A using Counting Sort
  
p = str # Reset the pointer to the start of the buffer
n -= 1 # Decrement n to exclude the last element from the output
for i in range(1, n + 1):
    putNum(B[i]) # Write each sorted element
    PutChar(' ') # Write a space between elements
putNum(B[i]) # Write the last element without a space
PutChar('\0') # Null-terminate the string
  
print(str) # Output the sorted string
  
