
import sys

# Read the number of elements in the array from the standard input
n = int(sys.stdin.readline())

# Initialize an array 'a' of size 'n' to store the input elements
a = [int(sys.stdin.readline()) for _ in range(n)]

# Initialize a list 's' of size 'n+1' to store the cumulative sum of elements in 'a'
s = [0] * (n+1)
for i in range(n):
    # Calculate the cumulative sum of elements in 'a' and store it in 's'
    s[i+1] = s[i] + a[i]

# Sort the list 's' in ascending order
s.sort()

# Initialize variables 'ans' and 'count' to calculate the answer
ans = 0
count = 0
# Iterate through the sorted list 's' to find the answer
for i in range(n):
    # If the current element in 's' is equal to the next element, increment 'count'
    if s[i] == s[i+1]:
        count += 1
    else: # If 'count' is greater than zero, calculate the number of combinations of 'count+1' elements taken 2 at a time and add it to 'ans'
        if count > 0:
            ans += combi(count+1, 2)
            count = 0

# If 'count' is greater than zero after the loop, calculate the number of combinations of 'count+1' elements taken 2 at a time and add it to 'ans'
if count > 0:
    ans += combi(count+1, 2)

# Print the answer
print(ans)

# Helper function to calculate the number of combinations of 'n' elements taken 'r' at a time
def combi(n, r):
    # Initialize the result 'c' to 1
    c = 1
    # Iterate from 1 to 'r' to calculate the result
    for i in range(1, r+1):
        # Multiply the result with the product of 'n-i+1' and the previous result
        c = c * (n - i + 1) // i
    # Return the result
    return c

