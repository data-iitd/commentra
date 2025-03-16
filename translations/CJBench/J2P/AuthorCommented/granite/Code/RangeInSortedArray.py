

def sorted_range(nums, key):
    left, right = 0, len(nums) - 1
    range = [-1, -1]
    altered_bin_search_iter(nums, key, left, right, range, True)
    altered_bin_search_iter(nums, key, left, right, range, False)
    return range

def altered_bin_search_iter(nums, key, left, right, range, go_left):
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] > key:
            right = mid - 1
        elif nums[mid] < key:
            left = mid + 1
        else:
            if go_left:
                if mid == 0 or nums[mid - 1]!= key:
                    range[0] = mid
                    return
                else:
                    right = mid - 1
            else:
                if mid == len(nums) - 1 or nums[mid + 1]!= key:
                    range[1] = mid
                    return
                else:
                    left = mid + 1

# Main method to take input and output the result
if __name__ == "__main__":
    import sys

    # Input the size of the array
    n = int(input())
    nums = list(map(int, input().split()))

    # Input the key to search
    key = int(input())

    # Get the range and print the result
    range = sorted_range(nums, key)
    print(range[0], range[1])

