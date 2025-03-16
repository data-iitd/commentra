import sys
import bisect

# Function to read an integer from input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read a list of integers from input
def get_int_list(n):
    return list(map(int, sys.stdin.readline().strip().split()))

# Function to find the minimum of two integers
def min_val(a, b):
    return a if a < b else b

# Function to find the maximum of two integers
def max_val(a, b):
    return a if a > b else b

# Main function containing the core logic of the program
def main_fn():
    # Read the number of elements
    n = get_int()
    # Read the integer list from input
    ls = get_int_list(n)
    # Create a reversed copy of the original list
    ls_rev = sorted(ls, reverse=True)
    # Sort the original list in ascending order
    ls.sort()

    # Initialize the answer variable
    ans = 0
    # Iterate through all pairs of elements in the sorted list
    for i in range(n):
        for j in range(i + 1, n):
            # Determine the minimum and maximum of the two selected elements
            p, q = min_val(ls[i], ls[j]), max_val(ls[i], ls[j])
            # Calculate the differences and sums needed for searching
            x, y = q - p, q + p

            # Find the left boundary for elements greater than x
            l = bisect.bisect_right(ls, x)
            # Find the right boundary for elements less than y
            r = n - bisect.bisect_left(ls_rev, y)

            # Calculate the number of valid elements in the range
            sum_val = r - l
            # Adjust the count if the current indices are within the range
            if l <= i < r:
                sum_val -= 1
            if l <= j < r:
                sum_val -= 1
            # Ensure the sum is non-negative
            sum_val = max(0, sum_val)
            # Accumulate the result
            ans += sum_val

    # Divide the final answer by 3 as per the problem requirements
    ans //= 3
    # Output the result
    print(ans)

# Entry point of the program
if __name__ == "__main__":
    main_fn()

# <END-OF-CODE>
