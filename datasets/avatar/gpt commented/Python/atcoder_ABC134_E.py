def binary_search(key):
    # Initialize the boundaries for binary search
    bad, good = -1, len(ans)
    
    # Continue searching while there is more than one element in the range
    while good - bad > 1:
        mid = (bad + good) // 2  # Calculate the middle index
        # If the last element of the mid list is less than the key, move the good boundary
        if ans[mid][-1] < key:
            good = mid
        else:
            # Otherwise, move the bad boundary
            bad = mid
            
    # Return the index where the key should be inserted
    return good

# Read the number of elements
N = int(input())

# Initialize an empty list to hold the subsequences
ans = []

# Iterate over the range of N to read each element
for _ in range(N):
    A = int(input())  # Read the current element
    idx = binary_search(A)  # Find the position to insert the element
    
    # If the index is equal to the length of ans, it means A is greater than all elements
    if idx == len(ans):
        ans.append([A])  # Start a new subsequence with A
    else:
        # Otherwise, append A to the existing subsequence at index idx
        ans[idx].append(A)

# Print the number of subsequences formed
print(len(ans))
