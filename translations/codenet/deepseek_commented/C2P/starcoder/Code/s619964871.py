# -*- coding: utf-8 -*-

# Function to merge two subarrays and count inversions
def sort(a, left, middle, right):
    l_arr = [0] * (middle-left+1)
    r_arr = [0] * (right-middle+1)
    cnt = 0
    # Copy elements into temporary arrays
    for i in range(middle-left):
        l_arr[i] = a[i+left]
    for i in range(right-middle):
        r_arr[i] = a[i+middle]
    # Sentinel values to simplify merging
    l_arr[middle-left] = 1e12
    r_arr[right-middle] = 1e12
    l = 0
    r = 0
    # Merge the two subarrays while counting inversions
    for i in range(right-left):
        if l_arr[l] <= r_arr[r]:
            a[left+i] = l_arr[l]
            l += 1
        else:
            a[left+i] = r_arr[r]
            cnt += middle-left-l
            r += 1
    return cnt

# Recursive function to count inversions in the array
def merge(a, left, right):
    if left+1 < right:
        middle = (left+right) / 2
        # Recursively count inversions in the left and right halves
        x1 = merge(a, left, middle)
        x2 = merge(a, middle, right)
        # Merge the two halves and count inversions in the merge step
        x3 = sort(a, left, middle, right)
        return x1+x2+x3
    else:
        return 0

# Main function to read input, count inversions, and print the result
def main():
    n = int(input()) # Read the size of the array
    a = [0] * n
    for i in range(n):
        a[i] = int(input()) # Read the elements of the array
    print(merge(a, 0, n)) # Count and print the number of inversions

if __name__ == '__main__':
    main()

