
nums = list(map(int, input().split(" ")))  # Take input from the user, split it into a list of integers
nums.sort(reverse=True)  # Sort the list of integers in descending order
print(nums[0]*10+nums[1]+nums[2])  # Print the result of an arithmetic operation on the sorted list

