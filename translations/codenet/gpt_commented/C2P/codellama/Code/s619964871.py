
#!/usr/bin/env python3

#
# FileName:     the_number_of_inversions_fix
# CreatedDate:  2020-06-05 16:25:10 +0900
# LastModified: 2020-07-06 22:22:35 +0900
#

# Uncomment the following line to disable garbage collection
# import gc; gc.disable()
# Uncomment the following line to disable print statement collected by default
# import io; io.stdout.write = lambda x: None

# Define a large constant to act as a sentinel value
unko = 1e12

# Function to merge two halves of an array and count inversions
def sort(a, left, middle, right):
    # Create temporary arrays for left and right halves
    l_arr = [0] * (middle - left + 1)
    r_arr = [0] * (right - middle + 1)
    cnt = 0  # Initialize inversion count

    # Copy data to temporary arrays
    for i in range(middle - left):
        l_arr[i] = a[i + left]
    for i in range(right - middle):
        r_arr[i] = a[i + middle]

    # Add sentinel values to the end of the temporary arrays
    l_arr[middle - left] = unko
    r_arr[right - middle] = unko

    l = 0  # Initialize pointers for left and right arrays
    r = 0

    # Merge the two halves back into the original array
    for i in range(right - left):
        if l_arr[l] <= r_arr[r]:
            a[left + i] = l_arr[l]
            l += 1
        else:
            a[left + i] = r_arr[r]
            r += 1
            cnt += middle - left - l

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


# Read the number of elements
n = int(input())

# Allocate memory for the array
a = [0] * n

# Read the elements into the array
for i in range(n):
    a[i] = int(input())

# Call the merge function and print the number of inversions
print(merge(a, 0, n))

# END-OF-CODE
