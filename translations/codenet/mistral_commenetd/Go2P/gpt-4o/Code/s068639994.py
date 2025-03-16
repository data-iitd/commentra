# Import necessary modules
import sys
import bisect

# Function to read an integer from standard input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read a list of integers from standard input
def get_int_list(n):
    return list(map(int, sys.stdin.readline().strip().split()))

# Function to find the minimum of two integers
def min_val(a, b):
    return a if a < b else b

# Function to find the maximum of two integers
def max_val(a, b):
    return a if a > b else b

# Main function
def main():
    # Get the number of elements in the input array
    n = get_int()
    # Get the input array
    ls = get_int_list(n)
    # Create a reversed copy of the input array
    ls_rev = ls[:]
    # Sort the input array in ascending order
    ls.sort()
    # Sort the reversed copy of the array in descending order
    ls_rev.sort(reverse=True)

    # Initialize the answer variable
    ans = 0
    # Iterate through all pairs of elements in the array
    for i in range(n):
        for j in range(i + 1, n):
            # Find the minimum and maximum elements of the current pair
            p, q = min_val(ls[i], ls[j]), max_val(ls[i], ls[j])
            # Calculate the difference between the maximum and minimum elements
            x, y = q - p, q + p
            # Find the indices of the elements greater than x and less than y in the sorted array and reversed array respectively
            l = bisect.bisect_right(ls, x)
            r = n - bisect.bisect_left(ls_rev, y)
            # Calculate the sum of the difference between the indices of the greater elements in the sorted array and reversed array
            sum_val = r - l
            # Check if the current pair lies within the range [l, r]
            if l <= i < r:
                sum_val -= 1
            if l <= j < r:
                sum_val -= 1
            # Ensure that the sum is not negative
            sum_val = max(0, sum_val)
            # Add the sum to the answer variable
            ans += sum_val

    # Divide the answer by 3 and print it
    ans //= 3
    print(ans)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
