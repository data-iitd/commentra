
# Read the number of elements from user input
n = int(input())

# Read 'n' integers from user input into a list
data = [int(input()) for _ in range(n)]

# Initialize variables to find the maximum value and its index
max_value = max(data)
max_index = data.index(max_value)

# Initialize a variable to calculate the sum of all elements except the maximum
sum_other_elements = sum(data) - max_value

# Compare the sum of the other elements with the maximum value and print the result
if sum_other_elements > max_value:
    print("Yes")
else:
    print("No")

