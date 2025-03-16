

def two_pointer(nums, target):
    nums.sort()
    result = []
    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        left, right = i + 1, len(nums) - 1
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
    n = int(input())
    nums = list(map(int, input().split()))
    target = int(input())
    result = two_pointer(nums, target)
    if not result:
        print("No triplets found.")
    else:
        for triplet in result:
            print(triplet)
