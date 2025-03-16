import sys
import math

def main():
    # Step 1: Reading Input
    n = int(sys.stdin.readline().strip())  # Read the integer n
    arr = list(map(float, sys.stdin.readline().strip().split()))  # Read the second line of input as a list of floats

    # Step 2: Processing Input
    non_int = 0  # Counter for non-integer values
    sum_before = 0.0  # Variable to store the sum of all numbers
    sum_int_parts = 0.0  # Variable to store the sum of their integer parts

    for num in arr:
        sum_before += num  # Add to the sum of all numbers
        if num != math.floor(num):
            non_int += 1  # Increment counter if the number is not an integer
        sum_int_parts += math.floor(num)  # Add the integer part of the number to the sum of integer parts

    # Step 3: Calculating Results
    max_sum = min(n, non_int) + sum_int_parts  # Calculate the maximum possible sum
    min_sum = max(0, non_int - n) + sum_int_parts  # Calculate the minimum possible sum

    # Determine the result
    if min_sum > sum_before:
        ans = min_sum - sum_before  # If the minimum sum is greater than the actual sum
    elif max_sum < sum_before:
        ans = sum_before - max_sum  # If the maximum sum is less than the actual sum
    else:
        x = sum_before - math.floor(sum_before)  # Calculate the fractional part of the sum
        ans = min(1 - x, x)  # Find the smallest difference to 0 or 1

    # Step 4: Output
    print(f"{ans:.3f}")  # Print the result with a precision of three decimal places

if __name__ == "__main__":
    main()

# <END-OF-CODE>
