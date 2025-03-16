
import sys

def twoPointer(nums, target):
    nums.sort()
    result = []
    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        left = i + 1
        right = len(nums) - 1
        while left < right:
            sum = nums[i] + nums[left] + nums[right]
            if sum == target:
                result.append([nums[i], nums[left], nums[right]])
                left += 1
                right -= 1
                while left < right and nums[left] == nums[left - 1]:
                    left += 1
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1
            elif sum < target:
                left += 1
            else:
                right -= 1
    return result

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    nums = [int(sys.stdin.readline()) for _ in range(n)]
    target = int(sys.stdin.readline())
    result = twoPointer(nums, target)
    if result:
        for triplet in result:
            print(triplet)
    else:
        print("No triplets found.")

