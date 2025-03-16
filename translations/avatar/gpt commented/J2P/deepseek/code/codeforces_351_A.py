import sys

def main():
    # Read the number of elements (n)
    n = int(input().strip())
    
    # Read the input line containing the numbers
    numbers = list(map(float, input().strip().split()))
    
    # Initialize variables for calculations
    non_int = 0
    sum_before = 0
    sum_int = 0
    
    # Loop through the input numbers
    for num in numbers:
        # Accumulate the total sum of the numbers
        sum_before += num
        
        # Check if the number is non-integer and update the counter
        if num != int(num):
            non_int += 1
        
        # Accumulate the sum of the integer parts of the numbers
        sum_int += int(num)
    
    # Calculate the maximum possible sum considering non-integer values
    max_sum = min(n, non_int) + sum_int
    
    # Calculate the minimum possible sum considering non-integer values
    min_sum = max(0, non_int - n) + sum_int
    
    # Determine the answer based on the calculated sums
    if min_sum > sum_before:
        ans = min_sum - sum_before
    elif max_sum < sum_before:
        ans = sum_before - max_sum
    else:
        # Calculate the minimum distance to the nearest integer
        x = sum_before - int(sum_before)
        ans = min(1 - x, x)
    
    # Print the final answer formatted to three decimal places
    print("{:.3f}".format(ans))

if __name__ == "__main__":
    main()
