# FileName:     the_number_of_inversions_fix.py
# CreatedDate:  2020-06-05 16:25:10 +0900
# LastModified: 2020-07-06 22:22:35 +0900

import sys

# Define a large constant to act as a sentinel value
UNKO = 1e12  

# Function to merge two halves of an array and count inversions
def sort(a, left, middle, right):
    # Create temporary arrays for left and right halves
    l_arr = a[left:middle] + [UNKO]
    r_arr = a[middle:right] + [UNKO]
    cnt = 0  # Initialize inversion count

    l = 0  # Pointer for left array
    r = 0  # Pointer for right array

    # Merge the two halves back into the original array
    for i in range(left, right):
        if l_arr[l] <= r_arr[r]:
            a[i] = l_arr[l]  # Take from left array
            l += 1
        else:
            a[i] = r_arr[r]  # Take from right array
            r += 1
            cnt += (middle - left - l)  # Count inversions

    return cnt  # Return the count of inversions

# Function to recursively divide the array and count inversions
def merge(a, left, right):
    if left + 1 < right:
        middle = (left + right) // 2  # Find the middle point
        x1 = merge(a, left, middle)  # Count inversions in the left half
        x2 = merge(a, middle, right)  # Count inversions in the right half
        x3 = sort(a, left, middle, right)  # Count inversions while merging
        return x1 + x2 + x3  # Return total count of inversions
    else:
        return 0  # Base case: no inversions if the segment has one or no elements

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())  # Read the number of elements
    a = list(map(int, sys.stdin.readline().strip().split()))  # Read the elements into the array

    # Call the merge function and print the number of inversions
    print(merge(a, 0, n))

# <END-OF-CODE>
