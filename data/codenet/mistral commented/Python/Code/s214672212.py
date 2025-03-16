
# Define an empty list called 'nums' to store the input integers
nums = []

# Use the map() function to apply the int() conversion to each element of the input list that is split by a space
nums = list(map(int, input().split(" ")))

# Sort the list in descending order using the sort() method
nums.sort(reverse=True)

# Multiply the first element by 10 and add the second and third elements
result = nums[0] * 10 + nums[1] + nums[2]

# Print the result
print(result)