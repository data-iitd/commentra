
import sys

def sorted_range(nums, key):
    left, right = -1, -1
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, left, right, True)
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, left, right, False)
    return [left, right]

def altered_bin_search_iter(nums, key, left, right, left_ref, right_ref, go_left):
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] > key:
            right = mid - 1
        elif nums[mid] < key:
            left = mid + 1
        else:
            if go_left:
                if mid == 0 or nums[mid - 1]!= key:
                    left_ref[0] = mid
                    return
                else:
                    right = mid - 1
            else:
                if mid == len(nums) - 1 or nums[mid + 1]!= key:
                    right_ref[0] = mid
                    return
                else:
                    left = mid + 1

if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    key = int(input())
    range = sorted_range(nums, key)
    print(range[0], range[1])

