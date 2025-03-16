def main():
    # Declare variables
    n = int(input())  # Read the number of integers
    numbers = list(map(int, input().split()))  # Read the integers into a list

    # Initialize min, max, and sum
    min_val = float('inf')
    max_val = float('-inf')
    total_sum = 0

    # Loop through the numbers
    for num in numbers:
        # Update min if the current number is smaller
        if min_val > num:
            min_val = num

        # Update max if the current number is larger
        if max_val < num:
            max_val = num

        # Add the current number to the sum
        total_sum += num

    # Print the minimum, maximum, and sum of the numbers
    print(min_val, max_val, total_sum)


# Call the main function
main()

