import sys 
import math 

# Define a constant number for modulo operations
num = 998244353 

# Read the number of pairs (n) from input
n = int(sys.stdin.readline()) 

# Create two lists to store the two sets of integers
ai = [] 
bi = [] 

# Read n pairs of integers from input
for i in range(n): 
    # Add the first integer of the pair to the first list
    ai.append(int(sys.stdin.readline())) 
    # Add the second integer of the pair to the second list
    bi.append(int(sys.stdin.readline())) 

# Sort both lists to prepare for median calculation
ai.sort() 
bi.sort() 

# Check if the number of elements is odd
if n % 2 == 1: 
    # Calculate the result for odd n using the median values
    print(bi[int(math.floor(n / 2))] - ai[int(math.floor(n / 2))] + 1) 
else: 
    # Calculate the average of the two middle values for even n
    b = (ai[int(math.floor(n / 2))] + ai[int(math.floor(n / 2)) - 1]) / 2 
    c = (bi[int(math.floor(n / 2))] + bi[int(math.floor(n / 2)) - 1]) / 2 
    # Calculate the result for even n and print it
    print(int(2 * (c - b) + 1)) 

# 