

n = int(input()) # Read the number of elements
d = int(input()) # Read the difference threshold
nums = [int(input()) for _ in range(n)] # Read the numbers and store them in the list

result = 0 # Initialize the result variable to 0
a = 0 # Initialize another variable to store the difference

for i in range(1, n):
    a = nums[i - 1] - nums[i] # Calculate the difference between consecutive elements
    if a >= 0:
        result += a // d + 1 # Update the result based on the difference
        nums[i] += (a // d + 1) * d # Adjust the current element to meet the condition

print(result) # Print the final result

