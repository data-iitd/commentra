
import sys

# Program to find all unique triplets in the array that sum to a target value.


def two_pointer(nums, target):
    """
    Two-pointer approach to find unique triplets that sum up to the target value.

    :param nums: The input array
    :param target: The target sum
    :return: A list of unique triplets
    """
    nums.sort()  # Sort the array for the two-pointer approach
    result = []

    for i in range(len(nums) - 2):
        # Avoid duplicates for the first number
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


if __name__ == "__main__":
    # Read the size of the array
    n = int(input())
    nums = list(map(int, input().split()))

    # Read the target sum
    target = int(input())

    # Solve the problem using the two-pointer approach
    result = two_pointer(nums, target)

    # Print the results
    if not result:
        print("No triplets found.")
    else:
        for triplet in result:
            print(triplet)

# 