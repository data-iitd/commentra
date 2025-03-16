# Import necessary libraries
import sys
from sortedcontainers import SortedSet

# Initialize an array 'a' of size N
a = []

def main():
    # Read the number of elements N from the standard input
    N = int(sys.stdin.readline().strip())

    # Read N elements from the standard input and store them in the array 'a'
    for _ in range(N):
        a.append(int(sys.stdin.readline().strip()))

    # Initialize an empty sorted set 'used_inds' to keep track of indices already used
    used_inds = SortedSet()

    ans = 0  # Initialize an answer variable 'ans' to 0

    # Iterate through each index i from 0 to N-1
    for i in range(N):
        cur_ind = a[i]  # Get the current element a[i]

        # Find the index of the left neighbor of the current index i in the set 'used_inds'
        left_border = -1 if not used_inds else used_inds[used_inds.bisect_left(cur_ind) - 1] if used_inds.bisect_left(cur_ind) > 0 else -1

        # Find the index of the right neighbor of the current index i in the set 'used_inds'
        right_border = N if used_inds.bisect_right(cur_ind) == len(used_inds) else used_inds[used_inds.bisect_right(cur_ind)]

        # Calculate the contribution of the current index i to the answer 'ans'
        ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)

        # Insert the index of the current element a[i] into the set 'used_inds'
        used_inds.add(cur_ind)

    # Print the final answer 'ans' to the standard output
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
