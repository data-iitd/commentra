
def min(nums):
    # Initialize min with the first element of nums
    min = nums[0]
    # Iterate over each value in nums to find the minimum
    for v in nums:
        # Update min if the current value is less than the current min
        if v < min:
            min = v
    # Return the minimum value found
    return min

if __name__ == "__main__":
    # Declare variables to hold input values
    n, a, b = map(int, input().split())

    # Calculate the minimum of n*a and b, and print the result
    print(min([n*a, b]))
