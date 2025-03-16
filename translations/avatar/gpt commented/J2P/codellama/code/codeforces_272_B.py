import sys 
import math 

# Read the number of integers to process
n = int(sys.stdin.readline()) 

# Array to count occurrences of integers based on their bit count
a = [0] * 33 

# Process each integer and count how many have the same number of set bits
for i in range(n): 
    a[rec(int(sys.stdin.readline()))] += 1 

# Variable to accumulate the final answer
answer = 0 

# Calculate the contribution to the answer from each bit count
for i in range(len(a)): 
    summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1) 
    answer += summ 

# Print the final answer as a long integer
print(int(answer)) 

# Method to count the number of set bits (1s) in the binary representation of x
def rec(x): 
    answer = 0 
    # Iterate through each bit position from 31 to 0
    for k in range(31, -1, -1): 
        # Check if the k-th bit is set
        if (x & (1 << k)) != 0: 
            answer += 1 
    return answer 

