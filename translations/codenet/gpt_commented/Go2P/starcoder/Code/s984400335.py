def min(*nums):
    # Initialize min with the first element of nums
    min = nums[0]
    # Iterate over each value in nums to find the minimum
    for v in nums:
        # Update min if the current value is less than the current min
        if v < min:
            min = v
    # Return the minimum value found
    return min

n, a, b = map(int, input().split())
print(min(n*a, b))

