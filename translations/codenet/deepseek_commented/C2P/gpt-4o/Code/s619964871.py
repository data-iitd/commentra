# Function to merge two subarrays and count inversions
def sort(a, left, middle, right):
    l_arr = a[left:middle]
    r_arr = a[middle:right]
    cnt = 0
    # Sentinel values to simplify merging
    l_arr.append(float('inf'))
    r_arr.append(float('inf'))
    l = 0
    r = 0
    # Merge the two subarrays while counting inversions
    for i in range(left, right):
        if l_arr[l] <= r_arr[r]:
            a[i] = l_arr[l]
            l += 1
        else:
            a[i] = r_arr[r]
            r += 1
            cnt += (middle - left - l)
    return cnt

# Recursive function to count inversions in the array
def merge(a, left, right):
    if left + 1 < right:
        middle = (left + right) // 2
        # Recursively count inversions in the left and right halves
        x1 = merge(a, left, middle)
        x2 = merge(a, middle, right)
        # Merge the two halves and count inversions in the merge step
        x3 = sort(a, left, middle, right)
        return x1 + x2 + x3
    else:
        return 0

# Main function to read input, count inversions, and print the result
if __name__ == "__main__":
    n = int(input())  # Read the size of the array
    a = list(map(int, input().split()))  # Read the elements of the array
    print(merge(a, 0, n))  # Count and print the number of inversions
