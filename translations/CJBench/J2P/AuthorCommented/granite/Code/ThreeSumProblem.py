

import sys
from typing import List

class Solution:
    def twoPointer(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        result = []

        for i in range(len(nums) - 2):
            # Avoid duplicates for the first number
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left, right = i + 1, len(nums) - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]

                if sum == target:
                    result.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1

                    # Avoid duplicates for the second and third numbers
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
                elif sum < target:
                    left += 1
                else:
                    right -= 1

        return result

def main():
    n = int(input("Enter the size of the array: "))
    nums = list(map(int, input("Enter the elements of the array: ").split()))
    target = int(input("Enter the target sum: "))

    solution = Solution()
    result = solution.twoPointer(nums, target)

    if not result:
        print("No triplets found.")
    else:
        for triplet in result:
            print(triplet)

if __name__ == "__main__":
    sys.exit(main())

