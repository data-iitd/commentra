
import sys

# Record the start time for performance measurement
start_time = time.time()

# Read the number of elements
n = int(input())

# Define a modulus value to prevent overflow
div = 10**9 + 7

# Initialize an array to hold the input values
A = [int(x) for x in input().split()]

# Variable to store the final answer
ans = 0

# Iterate through each bit position from 0 to 59
for i in range(60):
    a = 0 # Variable to accumulate contributions for the current bit
    count1 = 0 # Count of numbers with the i-th bit set
    
    # Count how many numbers have the i-th bit set
    for j in range(n):
        if (A[j] >> i & 1) == 1:
            count1 += 1
    
    # Calculate the contribution of the current bit to the answer
    a = a + count1 * (n - count1)
    
    # Shift the contribution left by i positions (equivalent to multiplying by 2^i)
    for j in range(i):
        a = (a << 1) % div
    
    # Add the contribution to the final answer and apply modulus
    ans += a
    ans %= div

# Output the final answer
print(ans)

# Record the end time for performance measurement
end_time = time.time()

# Print the execution time
print("Execution time:", end_time - start_time, "seconds")

