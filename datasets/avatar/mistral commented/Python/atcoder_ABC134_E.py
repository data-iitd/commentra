# Function to perform binary search on a sorted list
def binary_search(key):
    # Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    bad, good = -1, len(ans)

    # Continue searching until the subarray is not divided anymore
    while good - bad > 1:
        # Calculate the middle index of the subarray
        mid = (bad + good) // 2

        # Check if the middle element is less than the key
        if ans[mid][-1] < key:
            # If yes, update 'good' to be the new left index
            good = mid
        else:
            # If no, update 'bad' to be the new right index
            bad = mid

    # Return the index where the key is located
    return good

# Read the number of elements in the list
N = int(input())

# Initialize an empty list to store the elements
ans = []

# Read each element and perform binary search to find its position in the list
for _ in range(N):
    # Read an element
    A = int(input())

    # Perform binary search to find the index of the element
    idx = binary_search(A)

    # If the element is not already in the list, append it to the list
    if idx == len(ans):
        ans.append([A])
    else:
        # If the element is already in the list, append it to the existing list
        ans[idx].append(A)

# Print the number of unique elements in the list
print(len(ans))
