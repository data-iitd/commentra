def binary_search(key):
    # Initialize bad and good indices for binary search
    bad, good = -1, len(ans)
    
    # Perform binary search to find the correct position
    while good - bad > 1:
        mid = (bad + good) // 2
        if ans[mid][-1] < key:
            good = mid
        else:
            bad = mid
    
    # Return the index where the key should be inserted
    return good

# Read the number of elements
N = int(input())

# Initialize the list of lists
ans = []

# Read each element and insert it into the appropriate position
for _ in range(N):
    A = int(input())
    idx = binary_search(A)
    if idx == len(ans):
        # If the key should be inserted at the end, append a new sublist
        ans.append([A])
    else:
        # Otherwise, insert the key into the appropriate sublist
        ans[idx].append(A)

# Print the number of unique elements
print(len(ans))
