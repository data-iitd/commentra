import sys

def possible(N, A):
    # Calculate the sum of all elements in the array A
    sum = 0
    for i in range(N):
        sum += A[i]
    
    # Calculate the expected sum NS based on the formula for the sum of the first N natural numbers
    NS = (N * (N + 1)) / 2
    
    # Check if the total sum is divisible by NS; if not, return false
    if sum % NS!= 0:
        return False
    
    # Calculate the value of K which is the target average
    K = sum / NS
    
    # Verify the condition for each element in the array
    for i in range(N):
        # Determine the previous index in a circular manner
        j = i == 0? N - 1 : i - 1
        
        # Calculate the difference d needed to satisfy the condition
        d = K - (A[i] - A[j])
        
        # If d is negative or not divisible by N, return false
        if d < 0 or d % N!= 0:
            return False
    
    # If all conditions are satisfied, return true
    return True

# Read the number of elements N
N = int(raw_input().strip())

# Initialize an array A to hold N integers
A = []

# Populate the array A with N integers from user input
for i in range(N):
    A.append(int(raw_input().strip()))

# Check if it is possible to achieve the desired condition with the array A
if possible(N, A):
    # If possible, print "YES"
    print "YES"
else:
    # If not possible, print "NO"
    print "NO"

# 