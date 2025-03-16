
def min(nums):
    min = nums[0] # Initialize min with the first element
    for v in nums:
        if v < min: # Compare each element with the current min
            min = v # Update min if a smaller value is found
    return min # Return the smallest value

n, a, b = map(int, input().split()) # Read three integers from input

print(min([n*a, b])) # Print the minimum of n*a and b
