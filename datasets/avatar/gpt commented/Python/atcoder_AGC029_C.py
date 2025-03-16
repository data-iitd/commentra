import random

# Read input from the user
input()

# Parse the input into a list of integers
A = [int(_) for _ in input().split()]

# Filter the list to keep only non-increasing elements
A = [A[0]] + [j for i, j in zip(A, A[1:]) if i >= j]

# Get the length of the filtered list
N = len(A)

# Function to cut the array based on a given index
def cut(array, index):
    # If the index is less than 1, return an empty list
    if index < 1:
        return []
    
    # If the index is less than or equal to the first element, return it with the first element's second value
    if index <= array[0][0]:
        return [(index, array[0][1])]
    
    # Iterate backwards through the array to find the appropriate cut point
    for _ in range(len(array) - 1, 0, -1):
        if array[_ - 1][0] < index:
            return array[:_] + [(index, array[_][1])]

# Function to check if a certain condition is possible with K
def is_possible(K):
    # Initialize the dynamic programming array with the first element
    dp = [(A[0], 0)]
    
    # Iterate through the remaining elements in A
    for a in A[1:]:
        # If the current element is less than or equal to the last element in dp, cut dp
        if a <= dp[-1][0]:
            dp = cut(dp, a)
        else:
            # Otherwise, append the current element to dp
            dp += [(a, 0)]
        
        is_added = False
        
        # Iterate backwards through dp to check conditions
        for j in range(len(dp) - 1, -1, -1):
            # If the second value of the current tuple is less than K-1
            if dp[j][1] < K - 1:
                # Cut dp and increment the second value of the current tuple
                dp = cut(dp, dp[j][0] - 1) + [(dp[j][0], dp[j][1] + 1)]
                
                # If the last element in dp is less than a, append a to dp
                if dp[-1][0] < a:
                    dp += [(a, 0)]
                
                is_added = True
                break
        
        # If no element was added, return False
        if not is_added:
            return False
    
    # If all conditions are satisfied, return True
    return True

# Function to perform binary search to find the maximum K
def bis(x, y):
    # If the range is narrowed down to one element, return y
    if y == x + 1:
        return y
    # If is_possible is true for the midpoint, search in the left half
    elif is_possible((x + y) // 2):
        return bis(x, (x + y) // 2)
    # Otherwise, search in the right half
    else:
        return bis((x + y) // 2, y)

# Print the result of the binary search
print(bis(0, N))
