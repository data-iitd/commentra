# Import the necessary module
from collections import defaultdict

# Initialize an empty dictionary named 'm'
m = defaultdict(lambda: float('inf'))

# Iterate through all possible indices 'i' that satisfy the condition i*200 < 5001
for i in range(5001 // 200):
    # Iterate through all possible indices 'j' that satisfy the condition j*300 < 5001
    for j in range(5001 // 300):
        # Iterate through all possible indices 'k' that satisfy the condition k*500 < 5001
        for k in range(5001 // 500):
            # Calculate the composite index 'w'
            w = i * 200 + j * 300 + k * 500

            # Calculate the potential value 'p' for the given index 'w'
            p = (i // 5 * 5 * 380 * 0.8 + i % 5 * 380 +
                 j // 4 * 4 * 550 * 0.85 + j % 4 * 550 +
                 k // 3 * 3 * 850 * 0.88 + k % 3 * 850)

            # Update the dictionary 'm' with the minimum potential value
            m[w] = min(m[w], p)

# Read integers from the standard input and print their corresponding potential values from the dictionary 'm'
try:
    while True:
        n = int(input())
        if n == 0:
            break
        print(m[n])
except EOFError:
    pass

# <END-OF-CODE>
