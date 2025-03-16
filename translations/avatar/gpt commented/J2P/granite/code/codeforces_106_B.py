
```python
import sys

# Read the number of entries
n = int(input())

# Initialize a 2D array to store the input values
vec = []
for _ in range(n):
    vec.append(list(map(int, input().split())))

# Initialize variables to track the best option
ans = 500  # Default answer if no valid option is found
ans_price = 200000  # Set a high initial price

# Iterate through each entry to find the best option
for i in range(n):
    fl = 1  # Flag to check if the current entry is not dominated

    # Check if the current entry is dominated by any other entry
    for j in range(n):
        if vec[i][0] < vec[j][0] and vec[i][1] < vec[j][1] and vec[i][2] < vec[j][2]:
            fl = 0  # Set flag to 0 if dominated

    # If the current entry is not dominated, check its price
    if fl == 1:
        if vec[i][3] < ans_price:
            ans_price = vec[i][3]  # Update the best price found
            ans = i + 1  # Update the answer with the current index (1-based)

# Output the result
print(ans)
```

