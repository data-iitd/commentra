import sys  # Importing required module for input operations
import math  # Importing required module for mathematical operations

def main():
    # Reading the number of test cases
    n = int(sys.stdin.readline().strip())

    # Reading the elements of the array
    arr = list(map(float, sys.stdin.readline().strip().split()))
    non_int = 0  # Initializing variables
    sum_before = 0
    sum = 0

    # Iterating through the array elements and performing the required operations
    for num in arr:
        sum_before += num  # Adding the current number to the sum_before variable
        if num != math.floor(num):
            non_int += 1  # Incrementing the non_int variable if the current number is not an integer
        sum += math.floor(num)  # Adding the floor value of the current number to the sum variable

    # Calculating the maximum and minimum sums
    max_sum = min(n, non_int) + sum
    min_sum = max(0, non_int - n) + sum

    # Calculating the answer based on the given conditions
    if min_sum > sum_before:
        ans = min_sum - sum_before
    elif max_sum < sum_before:
        ans = sum_before - max_sum
    else:
        x = sum_before - math.floor(sum_before)
        ans = min(1 - x, x)

    # Printing the answer
    print(f"{ans:.3f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
