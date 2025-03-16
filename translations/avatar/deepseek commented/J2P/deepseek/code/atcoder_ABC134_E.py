from collections import Counter, OrderedDict
import sys

# Read the number of elements
n = int(sys.stdin.readline().strip())

# Initialize a Counter to store the frequency of numbers
counter = Counter()

# Loop n times to read n numbers
for _ in range(n):
    num = int(sys.stdin.readline().strip())

    # Check if there is no key less than the current number
    if num not in counter:
        # Increment the frequency of the current number
        counter[num] += 1
    else:
        # Find the largest key less than the current number
        keys = list(counter.keys())
        for key in reversed(keys):
            if key < num:
                # Decrement the frequency of the found key and remove it if frequency becomes zero
                counter[key] -= 1
                if counter[key] == 0:
                    del counter[key]
                # Increment the frequency of the current number
                counter[num] += 1
                break

# Calculate the sum of all frequencies in the counter
ans = sum(counter.values())

# Print the sum of frequencies
print(ans)
