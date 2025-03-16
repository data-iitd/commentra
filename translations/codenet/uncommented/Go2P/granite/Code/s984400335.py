
def min(nums):
    min = nums[0]
    for v in nums:
        if v < min:
            min = v
    return min

n, a, b = map(int, input().split())

print(min([n*a, b]))
