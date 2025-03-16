# Step 1: Take two integer inputs from the user
a, b = map(int, input().split())

# Step 2: Create a list named `lst` with three elements: sum, difference, and product of the inputs
lst = [a+b, a-b, a*b]

# Step 3: Print the maximum value from the list `lst`
print(max(lst))
