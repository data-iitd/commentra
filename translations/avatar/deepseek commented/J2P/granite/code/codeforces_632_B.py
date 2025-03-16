
import sys

# Step 1: Reading Input
n = int(input()) # Read the size of the array
a = list(map(int, input().split())) # Read the elements of the array
s = input() # Read the string

# Step 2: Reading a String

# Step 3: Initial Sum Calculation
sum = 0 # Initialize sum to store the sum of elements in array a where corresponding character in s is 'B'

# Step 4: First Loop
for i in range(len(s)):
    if s[i] == 'B':
        sum += a[i] # Add the element at position i in array a to sum if the character is 'B'

# Step 5: Main Logic
ans = sum # Initialize ans with the initial sum
sum1 = sum # Initialize sum1 for further calculations

# First nested loop to calculate the maximum possible sum by flipping characters in s
for i in range(len(s)):
    if s[i] == 'A':
        sum1 += a[i] # Add the element at position i in array a to sum1 if the character is 'A'
    else:
        sum1 -= a[i] # Subtract the element at position i in array a from sum1 if the character is 'B'
    ans = max(ans, sum1) # Update ans with the maximum value between ans and sum1

# Second nested loop to calculate the maximum possible sum by flipping characters in s from right to left
sum1 = sum # Reset sum1 to the initial sum
for i in range(len(s)-1, -1, -1):
    if s[i] == 'A':
        sum1 += a[i] # Add the element at position i in array a to sum1 if the character is 'A'
    else:
        sum1 -= a[i] # Subtract the element at position i in array a from sum1 if the character is 'B'
    ans = max(ans, sum1) # Update ans with the maximum value between ans and sum1

# Step 6: Output
print(ans) # Print the maximum sum found

