def min_value(*nums):
    min_val = nums[0]  # Initialize min with the first element
    for v in nums:
        if v < min_val:  # Compare each element with the current min
            min_val = v  # Update min if a smaller value is found
    return min_val  # Return the smallest value

if __name__ == "__main__":
    n, a, b = map(int, input().split())  # Read three integers from input
    print(min_value(n * a, b))  # Print the minimum of n*a and b

# <END-OF-CODE>
