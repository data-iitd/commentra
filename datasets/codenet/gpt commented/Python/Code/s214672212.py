# Read a line of input, split it by spaces, and convert each element to an integer
nums = list(map(int, input().split(" ")))

# Sort the list of numbers in descending order
nums.sort(reverse=True)

# Calculate the final result by multiplying the largest number by 10,
# then adding the second and third largest numbers, and print the result
print(nums[0] * 10 + nums[1] + nums[2])
