import sys
from collections import defaultdict

# Read the number of test cases
n = int(input().strip())

# Create a defaultdict to store the frequency of each number
freq_map = defaultdict(int)

# Loop through each test case
for _ in range(n):
    num = int(input().strip())

    if freq_map.get(num - 1, 0) == 0:
        # If the number is not present in the defaultdict
        freq_map[num] += 1
    else:
        # If the number is already present in the defaultdict
        freq_map[num - 1] -= 1
        if freq_map[num - 1] == 0:
            del freq_map[num - 1]
        freq_map[num] += 1

# Calculate the answer by summing up the frequencies
ans = sum(freq_map.values())

# Print the answer
print(ans)
