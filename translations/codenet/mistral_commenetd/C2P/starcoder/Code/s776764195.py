#include <stdio.h>

#define PutChar(c) ; *p = (char)(c); ++p; # Macro to write a character to the output string

#define MAX_N (2000001) # Maximum number of integers to be read
#define MAX_Ai (10001)   # Maximum value of an integer
#define STR_SIZE (10000010) # Size of the input string

def getNum(): # Function to read an integer from the input string
    return int(input())

def putNum(n): # Function to write an integer to the output string
    print(n)

def CountingSort(A, B, k, len): # Function to perform counting sort
    C = [0] * (k + 1) # Array to store the count of each integer
    for i in range(len): # Loop to count the number of times each integer occurs
        C[A[i]] += 1
    for i in range(1, k + 1): # Loop to calculate the cumulative sum of the counts
        C[i] += C[i - 1]
    for i in range(len - 1, -1, -1): # Loop to place the integers in the output array
        B[C[A[i]] - 1] = A[i]
        C[A[i]] -= 1

n = getNum() # Read the number of integers to be read
for i in range(n): # Loop to read the integers
    A[i] = getNum()
CountingSort(A, B, MAX_Ai, n) # Perform counting sort
for i in range(n): # Loop to write the sorted integers
    putNum(B[i])

