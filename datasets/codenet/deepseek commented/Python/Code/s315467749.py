
n = int(input())  # Read the size of the list S
S = list(map(int, input().split()))  # Read the list S of integers
q = int(input())  # Read the size of the list T
T = list(map(int, input().split()))  # Read the list T of integers

ans = 0  # Initialize the answer counter to 0

# Iterate over each integer i in the list T
for i in T:
    # Check if i is the last or first element of S
    if i == S[-1] or i == S[0]:
        ans += 1  # Increment the answer counter if i is found
    else:
        # Perform binary search to find i in S
        left = 0  # Initialize the left pointer to the start of S
        right = n-1  # Initialize the right pointer to the end of S
        while right-left > 1:  # Continue until the search space is reduced to 2 elements
            mid = (left+right)//2  # Calculate the middle index
            if S[mid] == i:  # Check if the middle element is the target
                ans += 1  # Increment the answer counter if i is found
                break  # Exit the loop as we found the element
            elif S[mid] < i:  # Adjust the search space to the right half
                left = mid
            else:  # Adjust the search space to the left half
                right = mid

print(ans)  # Print the final count of elements found in S from T

