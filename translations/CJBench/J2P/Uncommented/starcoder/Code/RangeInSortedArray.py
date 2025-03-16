
def sortedRange(nums, key):
    range = [-1, -1]
    alteredBinSearchIter(nums, key, 0, len(nums) - 1, range, True)
    alteredBinSearchIter(nums, key, 0, len(nums) - 1, range, False)
    return range

def alteredBinSearchIter(nums, key, left, right, range, goLeft):
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] > key:
            right = mid - 1
        elif nums[mid] < key:
            left = mid + 1
        else:
            if goLeft:
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
    return

if __name__ == '__main__':
    import sys
    scanner = sys.stdin
    n = int(scanner.readline())
    nums = [int(scanner.readline()) for _ in range(n)]
    key = int(scanner.readline())
    range = sortedRange(nums, key)
    print(range[0], range[1])
    scanner.close()

