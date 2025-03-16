# Read the number of elements in the list S
n = int(input())

# Read the elements of the list S and convert them to a list of integers
S = list(map(int, input().split()))

# Read the number of queries
q = int(input())

# Read the elements of the query list T and convert them to a list of integers
T = list(map(int, input().split()))

# Initialize a counter for the number of matches found
ans = 0

# Iterate through each element in the query list T
for i in T:
    # Check if the current query element is equal to the first or last element of S
    if i == S[-1] or i == S[0]:
        # If it matches, increment the counter
        ans += 1
    else:
        # Initialize binary search boundaries
        left = 0
        right = n - 1
        
        # Perform binary search to find the element in S
        while right - left > 1:
            # Calculate the middle index
            mid = (left + right) // 2
            
            # Check if the middle element is the target
            if S[mid] == i:
                # If found, increment the counter and break the loop
                ans += 1
                break
            # If the middle element is less than the target, search in the right half
            elif S[mid] < i:
                left = mid
            # If the middle element is greater than the target, search in the left half
            else:
                right = mid

# Print the total number of matches found
print(ans)
