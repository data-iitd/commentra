def min(*nums):
    # Initializing the minimum value with the first integer
    min_val = nums[0]

    # Iterating through the tuple 'nums' to find the minimum value
    for v in nums:
        # If the current value is less than the minimum value, update the minimum value
        if v < min_val:
            min_val = v

    # Returning the minimum value
    return min_val

# Main function declaration
def main():
    # Declaring three integer variables for reading input values
    n, a, b = map(int, input().split())

    # Printing the minimum value between 'n*a' and 'b'
    print(min(n*a, b))

# Calling the main function
if __name__ == "__main__":
    main()

