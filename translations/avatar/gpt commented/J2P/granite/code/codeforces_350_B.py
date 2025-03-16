
import sys

# Read the number of elements
n = int(input())

# Initialize arrays to store input values and counts
a = [0] * (n + 1)
b = [0] * (n + 1)
num = [0] * (n + 1)

# Read values into array a
for i in range(1, n + 1):
    a[i] = int(input())

# Read values into array b
for i in range(1, n + 1):
    b[i] = int(input())

# Count occurrences of each value in array b
for i in range(1, n + 1):
    num[b[i]] += 1

# Initialize variables for tracking the longest sequence and its representation
ss = ""
ans = 0
st = [False] * (n + 1)

# Iterate through each element to find the longest valid sequence
for i in range(1, n + 1):
    # Check if the current element in a is 1
    if a[i] == 1:
        st[i] = True # Mark this index as visited
        sb = []
        x = b[i] # Start with the corresponding value in b
        sss = [i] # Append the current index
        sb.append(sss) # Reverse and append to the sequence
        
        s = 1 # Initialize the length of the current sequence
        
        # Continue to build the sequence while conditions are met
        while not st[x] and num[x] == 1 and x!= 0 and a[x]!= 1:
            sss = [x] # Append the next index
            sb.append(sss) # Reverse and append to the sequence
            st[x] = True # Mark this index as visited
            x = b[x] # Move to the next index in b
            s += 1 # Increment the sequence length

# Update the longest sequence found if the current one is longer
if s > ans:
    ans = s
    ss = sb[::-1] # Store the longest sequence

# Output the length of the longest sequence and the sequence itself
print(ans)
print(ss)
