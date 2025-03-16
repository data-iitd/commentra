
import sys

def sorted_range(nums, key):
    range = [-1, -1]
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, range, True)
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, range, False)
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
                if mid == 0 or nums[mid - 1] != key:
                    range[0] = mid
                    return
                else:
                    right = mid - 1
            else:
                if mid == len(nums) - 1 or nums[mid + 1] != key:
                    range[1] = mid
                    return
                else:
                    left = mid + 1

def main():
    n = int(sys.stdin.readline())
    nums = list(map(int, sys.stdin.readline().split()))
    key = int(sys.stdin.readline())
    range = sorted_range(nums, key)
    print(range[0], range[1])

if __name__ == "__main__":
    main()

