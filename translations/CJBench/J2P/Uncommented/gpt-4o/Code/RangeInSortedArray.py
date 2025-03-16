def sorted_range(nums, key):
    range_ = [-1, -1]
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, range_, True)
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, range_, False)
    return range_

def altered_bin_search_iter(nums, key, left, right, range_, go_left):
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] > key:
            right = mid - 1
        elif nums[mid] < key:
            left = mid + 1
        else:
            if go_left:
                if mid == 0 or nums[mid - 1] != key:
                    range_[0] = mid
                    return
                else:
                    right = mid - 1
            else:
                if mid == len(nums) - 1 or nums[mid + 1] != key:
                    range_[1] = mid
                    return
                else:
                    left = mid + 1

if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    key = int(input())
    range_ = sorted_range(nums, key)
    print(range_[0], range_[1])
# <END-OF-CODE>
