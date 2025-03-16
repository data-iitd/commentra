

n = int(input()) # Reading the number of elements in the array from the user
ans = list(map(int, input().split())) # Reading the array elements from the user and converting them to integers

# Sorting the array in ascending order
ans.sort()

# Initializing a variable to keep track of the count
count = ans[-1] # The last element of the sorted array is the maximum element

# Iterating through the array from the second last element to the first
for i in range(n-2, -1, -1):
    # If the current element is less than the next element, add it to the count
    if ans[i] < ans[i+1]:
        count += ans[i]
    else: # If the current element is greater than or equal to the next element
        # Decrement the current element until it becomes less than the next element
        while ans[i] >= ans[i+1]:
            ans[i] -= 1

        # If the current element is still greater than or equal to the next element, add it to the count
        if ans[i] > 0:
            count += ans[i]

# Printing the final count
print(count) # Printing the final count

