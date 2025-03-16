def check(lis, k, mid):
    # This function checks if it's possible to distribute the elements of lis
    # such that each element is at most mid and the total number of operations
    # does not exceed k.
    for i in lis:
        if i % mid == 0:  # If i is divisible by mid, increment k by 1.
            k += 1
        k -= i // mid  # Subtract the number of elements that can be handled by mid from k.
    return k >= 0  # Return True if k is non-negative, else False.

# Read the number of elements (n) and the initial value of k from input.
n, k = map(int, input().split())

# Read the list of integers from input.
lis = list(map(int, input().split()))

# Initialize the search range with 1 and the maximum value in the list.
a, b = 1, max(lis)

# Initialize the answer with the maximum value in the list.
ans = b

# Perform a binary search to find the maximum value of mid that satisfies the condition.
while a <= b:
    mid = (a + b) // 2  # Calculate the middle value of the current search range.
    if check(lis, k, mid):  # Check if the current mid value is valid.
        ans = mid  # Update the answer to the current mid value.
        b = mid - 1  # Adjust the upper bound of the search range.
    else:
        a = mid + 1  # Adjust the lower bound of the search range.

# Print the result, which is the maximum value of mid that satisfies the condition.
print(ans)
