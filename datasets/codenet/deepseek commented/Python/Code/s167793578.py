# This code calculates the number of ways to choose 2 items from N items and M items,
# and then prints the sum of these two values.

# Step 1: Take two integers N and M as input and map them to the variables N and M.
N, M = map(int, input().split())

# Step 2: Calculate the number of ways to choose 2 items from N items.
a = N * (N - 1) // 2

# Step 3: Calculate the number of ways to choose 2 items from M items.
b = M * (M - 1) // 2

# Step 4: Add the results from Step 2 and Step 3 and print the sum.
print(a + b)

# This code calculates the number of ways to choose 2 items from N items and M items,
# and then prints the sum of these two values.

# Step 1: Take two integers N and M as input and map them to the variables N and M.
N, M = map(int, input().split())

# Step 2: Calculate the number of ways to choose 2 items from N items.
a = N * (N - 1) // 2

# Step 3: Calculate the number of ways to choose 2 items from M items.
b = M * (M - 1) // 2

# Step 4: Add the results from Step 2 and Step 3 and print the sum.
print(a + b)