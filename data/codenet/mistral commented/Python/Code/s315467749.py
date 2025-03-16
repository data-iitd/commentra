#######
# Code
#######

# Read the number of elements in the list 'S' from the user
n = int(input())

# Read the list 'S' from the user and convert it into a list of integers
S = list(map(int, input().split()))

# Read the number of queries 'q' from the user
q = int(input())

# Read the list 'T' of queries from the user and convert it into a list of integers
T = list(map(int, input().split()))

# Initialize the answer variable to zero
ans = 0

# Iterate through each query 'i' in the list 'T'
for i in T:

    # Check if the query 'i' is the first or last element of the list 'S'
    if i == S[-1] or i == S[0]:
        # If yes, increment the answer variable
        ans += 1

    # If the query 'i' is not the first or last element of the list 'S',
    # then perform a binary search to find its index in the list 'S'
    else:
        # Initialize the left and right pointers to the first and last indices of the list 'S'
        left = 0
        right = n-1

        # Perform binary search to find the index of the query 'i' in the list 'S'
        while right-left > 1:
            # Calculate the middle index of the current search interval
            mid = (left+right)//2

            # If the middle element is equal to the query 'i',
            # then increment the answer variable and break out of the loop
            if S[mid] == i:
                ans += 1
                break

            # If the middle element is less than the query 'i',
            # then update the left pointer to the middle index + 1
            elif S[mid] < i:
                left = mid + 1

            # If the middle element is greater than the query 'i',
            # then update the right pointer to the middle index - 1
            else:
                right = mid - 1

# Print the final answer
print(ans)
