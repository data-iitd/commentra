def rememberTheNumber(nums, i, operations, ans):
    # If the index i is greater than or equal to 3, return to limit recursion depth
    if i >= 3:
        return
    
    # Iterate over pairs of numbers to perform operations
    for j in range(4):
        for k in range(j + 1, 4):
            if nums[j] != -1 and nums[k] != -1:
                s = nums[j]
                nums[j] = -1  # Mark the number as used
                t = nums[k]
                
                # Perform the operation based on the current operation symbol
                if operations[i] == '+':
                    nums[k] = s + t
                elif operations[i] == '*':
                    nums[k] = s * t
                
                # If it's the last operation and the result is smaller than the current minimum, update ans
                if i == 2 and nums[k] < ans[0]:
                    ans[0] = nums[k]
                
                # Recursively call the function with updated parameters
                rememberTheNumber(nums, i + 1, operations, ans)
                
                # Restore the original numbers to try other combinations
                nums[j] = s
                nums[k] = t

# Read input numbers and operations
nums = list(map(int, input().split()))
operations = list(map(str, input().split()))

# Initialize the answer list with a large number
ans = [10000000000000000000000000]

# Call the function with initial parameters
rememberTheNumber(nums, 0, operations, ans)

# Print the smallest number found
print(ans[0])
