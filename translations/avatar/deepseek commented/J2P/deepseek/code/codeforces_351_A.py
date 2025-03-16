import sys

def main():
    # Step 1: Reading Input
    n = int(input().strip())  # Read the integer n
    input_line = input().strip()  # Read the second line of input
    tokens = input_line.split()  # Split the input line into tokens

    # Step 2: Processing Input
    arr = []  # List to store the floating-point numbers
    non_int = 0  # Counter for non-integer values
    sum_before = 0  # Variable to store the sum of all numbers
    sum_int = 0  # Variable to store the sum of integer parts

    for token in tokens:
        num = float(token)  # Convert each token to a float
        sum_before += num  # Add to the sum of all numbers
        if num != int(num):  # Check if the number is not an integer
            non_int += 1
        sum_int += int(num)  # Add the integer part of the number to the sum of integer parts
        arr.append(num)  # Append the number to the list

    # Step 3: Calculating Results
    max_sum = min(n, non_int) + sum_int  # Calculate the maximum possible sum
    min_sum = max(0, non_int - n) + sum_int  # Calculate the minimum possible sum
    ans = 0  # Variable to store the result

    if min_sum > sum_before:
        ans = min_sum - sum_before  # If the minimum sum is greater than the actual sum
    elif max_sum < sum_before:
        ans = sum_before - max_sum  # If the maximum sum is less than the actual sum
    else:
        x = sum_before - int(sum_before)  # Calculate the fractional part of the sum
        ans = min(1 - x, x)  # Find the smallest difference to 0 or 1

    # Step 4: Output
    print("{:.3f}".format(ans))  # Print the result with a precision of three decimal places

if __name__ == "__main__":
    main()
