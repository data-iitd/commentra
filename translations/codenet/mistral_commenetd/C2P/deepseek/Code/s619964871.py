# FileName:     the_number_of_inversions_fix
# CreatedDate:  2020-06-05 16:25:10 +0900
# LastModified: 2020-07-06 22:22:35 +0900

import sys

# Function to sort a subarray using merge-sort algorithm
def sort(a, left, middle, right):
    l_arr = a[left:middle]  # Copy elements from the left subarray to a temporary array
    r_arr = a[middle:right]  # Copy elements from the right subarray to a temporary array
    cnt = 0  # Initialize inversion count to zero

    # Set the last element of left subarray and right subarray to a large value
    l_arr.append(float('inf'))
    r_arr.append(float('inf'))

    i, j = 0, 0  # Initialize pointers for left and right subarrays

    # Merge the sorted subarrays back to the original array and count inversions
    for k in range(left, right):
        if l_arr[i] <= r_arr[j]:  # If current element from left subarray is smaller than or equal to current element from right subarray
            a[k] = l_arr[i]  # Copy the smaller element to the original array
            i += 1
        else:  # If current element from left subarray is greater than the current element from right subarray
            a[k] = r_arr[j]  # Copy the smaller element to the original array
            j += 1
            cnt += middle - left - i  # Increment inversion count

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
def main():
    n = int(sys.stdin.readline().strip())  # Read the number of elements in the array
    a = list(map(int, sys.stdin.readline().strip().split()))  # Read the elements of the array from the standard input

    print(merge(a, 0, n))  # Call the merge-sort function and print the result

if __name__ == "__main__":
    main()
