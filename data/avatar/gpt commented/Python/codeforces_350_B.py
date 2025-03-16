# Read the number of elements
n = int(input())

# Read the list 't' and prepend a 0 for 1-based indexing
t = [0] + list(map(int, input().split()))

# Read the list 'a' and prepend a 0 for 1-based indexing
a = [0] + list(map(int, input().split()))

# Initialize the answer list and a count list to track occurrences
ans, cnt = [], [0 for i in range(n + 1)]

# Count the occurrences of each element in list 'a'
for i in a:
    cnt[i] += 1

# Iterate through each index from 1 to n
for i in range(1, n + 1):
    # Check if the current element in 't' is 1
    if t[i] == 1:
        # Initialize a current path list starting with the current index
        crt = [i]
        # Set x to the corresponding value in 'a'
        x = a[i]
        
        # Continue to follow the chain while the count of x is 1
        while cnt[x] == 1:
            crt.append(x)  # Add x to the current path
            x = a[x]  # Move to the next index in the chain
        
        # Update the answer if the current path is longer than the previous answer
        if len(crt) > len(ans):
            ans = crt[:]  # Store a copy of the current path

# Reverse the answer list to maintain the original order
ans.reverse()

# Print the length of the longest path found
print(len(ans))

# Print the elements of the longest path as a space-separated string
print(' '.join(map(str, ans)))
