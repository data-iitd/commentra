import sys
import bisect

def main_fn():
    # Get the number of elements in the list.
    n = get_int()
    # Get the list of integers.
    ls = get_int_list(n)
    # Create a reversed version of the list.
    ls_rev = sorted(ls, reverse=True)
    # Sort the original list in ascending order.
    ls.sort()

    # Initialize the answer variable.
    ans = 0
    # Loop through the list to calculate the answer.
    for i in range(n):
        for j in range(i + 1, n):
            # Calculate p and q based on the current elements.
            p, q = min(ls[i], ls[j]), max(ls[i], ls[j])
            # Calculate x and y based on p and q.
            x, y = q - p, q + p

            # Find the left boundary using binary search.
            l = bisect.bisect_right(ls, x)
            # Find the right boundary using binary search.
            r = n - bisect.bisect_left(ls_rev, y)

            # Calculate the sum of valid pairs.
            sum_pairs = r - l
            # Adjust the sum if the current indices are within the range.
            if l <= i < r:
                sum_pairs -= 1
            if l <= j < r:
                sum_pairs -= 1
            # Ensure the sum is not negative.
            sum_pairs = max(0, sum_pairs)
            # Add the sum to the answer.
            ans += sum_pairs

    # Divide the answer by 3 to get the final result.
    ans //= 3
    # Print the final answer.
    puts(ans)

# Helper functions to read input.
def get_int():
    return int(sys.stdin.readline().strip())

def get_int_list(n):
    return list(map(int, sys.stdin.readline().strip().split()))

def puts(a):
    print(a)

# Main function to initialize the program.
if __name__ == "__main__":
    main_fn()

# <END-OF-CODE>
