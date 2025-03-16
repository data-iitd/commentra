def two_pointer(nums, target):
    nums.sort()  # Sort the array for the two-pointer approach
    result = []

    for i in range(len(nums) - 2):
        # Avoid duplicates for the first number
        if i > 0 and nums[i] == nums[i - 1]:
            continue

        left, right = i + 1, len(nums) - 1
        while left < right:
            sum_ = nums[i] + nums[left] + nums[right]

            if sum_ == target:
                result.append([nums[i], nums[left], nums[right]])
                left += 1
                right -= 1

                # Avoid duplicates for the second and third numbers
                while left < right and nums[left] == nums[left - 1]:
                    left += 1
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1
            elif sum_ < target:
                left += 1
            else:
                right -= 1

    return result


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    # Read the size of the array
    n = int(data[0])
    nums = list(map(int, data[1:n+1]))

    # Read the target sum
    target = int(data[n+1])

    # Solve the problem using the two-pointer approach
    result = two_pointer(nums, target)

    # Print the results
    if not result:
        print("No triplets found.")
    else:
        for triplet in result:
            print(triplet)


main()
