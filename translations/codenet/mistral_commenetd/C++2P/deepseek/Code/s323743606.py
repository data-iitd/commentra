from collections import defaultdict
import sys

# Initialize an empty dictionary named 'm'
m = defaultdict(lambda: float('inf'))

# Iterate through all possible indices 'i' that satisfy the condition i*200 < 5001
for i in range(5001 // 200 + 1):
    # Iterate through all possible indices 'j' that satisfy the condition j*300 < 5001
    for j in range(5001 // 300 + 1):
        # Iterate through all possible indices 'k' that satisfy the condition k*500 < 5001
        for k in range(5001 // 500 + 1):
            # Calculate the composite index 'w'
            w = i * 200 + j * 300 + k * 500

            # Calculate the potential value 'p' for the given index 'w'
            p = i // 5 * 5 * 380 * 0.8 + i % 5 * 380 \
                + j // 4 * 4 * 550 * 0.85 + j % 4 * 550 \
                + k // 3 * 3 * 850 * 0.88 + k % 3 * 850

            # If the dictionary 'm' already contains the index 'w', update its value with the minimum of the current potential value and the existing one
            if w in m:
                m[w] = min(m[w], p)

            # If the dictionary 'm' does not contain the index 'w', add it with the current potential value as its value
            else:
                m[w] = p

# Read integers from the standard input and print their corresponding potential values from the dictionary 'm'
while True:
    n = int(sys.stdin.readline().strip())
    if n == 0:
        break
    print(m[n])
