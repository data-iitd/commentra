
# Step 1: Import the necessary module
import sys

# Step 2: Read input numbers from the command line
s = list(map(int, sys.argv[1:]))

# Step 3: Sort the array
s.sort()

# Step 4: Print the last four numbers of the sorted array
for i in range(9, 6, -1):
    print(s[i])

