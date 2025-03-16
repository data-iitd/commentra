def min_value(*nums):
    # Initialize min with the first element of nums
    min_val = nums[0]
    # Iterate over each value in nums to find the minimum
    for v in nums:
        # Update min if the current value is less than the current min
        if v < min_val:
            min_val = v
    # Return the minimum value found
    return min_val

def main():
    # Read three integers from standard input
    n, a, b = map(int, input().split())
    
    # Calculate the minimum of n*a and b, and print the result
    print(min_value(n * a, b))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
