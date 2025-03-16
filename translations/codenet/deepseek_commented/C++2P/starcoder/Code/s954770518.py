# Step 1: Read the input numbers into the array
s = [int(input()) for i in range(10)]

# Step 2: Sort the array
s.sort()

# Step 3: Print the last four numbers of the sorted array
for i in range(6, 10):
    print(s[i])

# 