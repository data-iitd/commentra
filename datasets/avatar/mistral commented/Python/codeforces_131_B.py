# Import necessary modules
import sys

# Function to read input from standard input
input = sys.stdin.readline

# Use Counter from collections module to count occurrences of numbers
from collections import Counter

# Read the number of test cases
n = int(input())

# Initialize a Counter object 'w' to store the occurrences of numbers
w = Counter(map(int, input().split()))

# Initialize a counter 'c' to store the result
c = 0

# Iterate through each number 'i' in the Counter 'w'
for i in w:
    # If the number 'i' is zero, then add its occurrences multiplied by (its occurrences - 1) to the counter 'c'
    if i == 0:
        c += w[i] * (w[i] - 1)
    # If the number '-i' is present in the Counter 'w', then add its occurrences multiplied by the occurrences of 'i' to the counter 'c'
    elif -i in w:
        c += w[i] * w[-i]

# Print the result divided by 2
print(c // 2)
