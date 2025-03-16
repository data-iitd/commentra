
# Take input as a string
input_str = input()

# Split the input string by space to get a list of integers
candy = input_str.split()

# Convert each element in the list to an integer using map() function
candy = list(map(int, candy))

# Sort the list using sorted() function
candy = sorted(candy)

# Check if the sum of the first two elements and the last element are equal
if candy[0] + candy[1] == candy[2]:
 print("Yes")
else:
 print("No")