def sorted_range(nums, key):
    range_indices = [-1, -1]
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, range_indices, True)
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, range_indices, False)
    return range_indices

def altered_bin_search_iter(nums, key, left, right, range_indices, go_left):
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] > key:
            right = mid - 1
        elif nums[mid] < key:
            left = mid + 1
        else:
            if go_left:
                if mid == 0 or nums[mid - 1] != key:
                    range_indices[0] = mid
                    return
                else:
                    right = mid - 1
            else:
                if mid == len(nums) - 1 or nums[mid + 1] != key:
                    range_indices[1] = mid
                    return
                else:
                    left = mid + 1

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    key = int(input())
    range_indices = sorted_range(nums, key)
    print(range_indices[0], range_indices[1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
