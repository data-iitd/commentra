import sys; # Importing the sys module for reading input from the console

# Reading the number of elements (n) and the divisor (d) from user input
n = int(sys.stdin.readline())
d = int(sys.stdin.readline())

# Initializing an array to hold the numbers
nums = []

# Reading n integers from user input and storing them in the nums array
for i in range(n):
    nums.append(int(sys.stdin.readline()))

# Initializing result variable to count the total adjustments made
result = 0
a = 0 # Variable to hold the difference between consecutive elements

# Looping through the nums array starting from the second element
for i in range(1, n):
    # Calculating the difference between the previous and current element
    a = (nums[i - 1] - nums[i])
    
    # If the difference is non-negative, adjustments are needed
    if a >= 0:
        # Calculating how many times we can adjust the current element
        result += a // d + 1 
        
        # Adjusting the current element to maintain the required condition
        nums[i] += (a // d + 1) * d; 

# Printing the total number of adjustments made
print(result)

