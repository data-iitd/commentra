def rememberTheNumber(nums, i, operations, ans):
    # Base case: If we have performed 3 operations, exit the function
    if i >= 3:
        return
    
    # Iterate through all pairs of numbers in the list
    for j in range(4):
        for k in range(j + 1, 4):
            # Check if both numbers are not marked as used (-1)
            if (nums[j] != -1 and nums[k] != -1):
                # Store the current values of nums[j] and nums[k]
                s = nums[j]
                nums[j] = -1  # Mark nums[j] as used
                t = nums[k]
                
                # Perform the operation based on the current operation symbol
                if (operations[i] == '+'):
                    nums[k] = s + t  # Addition operation
                elif (operations[i] == '*'):
                    nums[k] = s * t  # Multiplication operation
                
                # If we are at the last operation and the result is less than the current minimum, update it
                if (i == 2 and nums[k] < ans[0]):
                    ans[0] = nums[k]
                
                # Recursively call the function for the next operation
                rememberTheNumber(nums, i + 1, operations, ans)
                
                # Backtrack: Restore the original values of nums[j] and nums[k]
                nums[j] = s
                nums[k] = t

# Read input numbers and operations from the user
nums = list(map(int, input().split()))
operations = list(map(str, input().split()))

# Initialize the answer with a very large number
ans = [10000000000000000000000000]

# Start the recursive function with the initial parameters
rememberTheNumber(nums, 0, operations, ans)

# Print the minimum result found after all operations
print(ans[0])
