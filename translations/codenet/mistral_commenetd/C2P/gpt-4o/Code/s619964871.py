# FileName:     the_number_of_inversions_fix.py
# CreatedDate:  2020-06-05 16:25:10 +0900
# LastModified: 2020-07-06 22:22:35 +0900

import sys

unko = 1e12  # A large value to represent infinity

# Function to sort a subarray using merge-sort algorithm
def sort(a, left, middle, right):
    l_arr = a[left:middle]  # Left subarray
    r_arr = a[middle:right]  # Right subarray
    cnt = 0  # Initialize inversion count to zero

    # Append a large value to both subarrays
    l_arr.append(unko)
    r_arr.append(unko)

    l = 0  # Pointer for left subarray
    r = 0  # Pointer for right subarray

    # Merge the sorted subarrays back to the original array and count inversions
    for i in range(left, right):
        if l_arr[l] <= r_arr[r]:  # If current element from left subarray is smaller or equal
            a[i] = l_arr[l]  # Copy the smaller element to the original array
            l += 1  # Move the pointer in the left subarray
        else:  # If current element from left subarray is greater
            a[i] = r_arr[r]  # Copy the smaller element to the original array
            r += 1  # Move the pointer in the right subarray
            cnt += (middle - left - l)  # Increment inversion count

    return cnt  # Return the number of inversions

# Recursive function to merge-sort the given array
def merge(a, left, right):
    if left + 1 < right:  # If the subarray has more than one element
        middle = (left + right) // 2  # Calculate the middle index of the subarray
        x1 = merge(a, left, middle)  # Merge-sort the left subarray
        x2 = merge(a, middle, right)  # Merge-sort the right subarray
        x3 = sort(a, left, middle, right)  # Merge the sorted subarrays and count inversions
        return x1 + x2 + x3  # Return the total number of inversions
    else:  # If the subarray has only one element
        return 0  # No inversions are present

# Main function to read input and call merge-sort function
if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())  # Read the number of elements in the array
    a = list(map(int, sys.stdin.readline().strip().split()))  # Read the elements of the array

    print(merge(a, 0, n))  # Call the merge-sort function and print the result
