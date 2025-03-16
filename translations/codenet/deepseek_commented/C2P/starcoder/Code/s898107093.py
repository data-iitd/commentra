# Include string manipulation functions
# Include memory allocation functions
# Include standard input/output functions

# Declare pointers to pointers for Tarō and Hanako's strings
t = []
h = []

# Declare number of rounds, scores, and loop index
n = 0
taro = 0
hanako = 0
i = 0

# Read the number of rounds
n = int(input())

# Loop through each round
for i in range(n):
    # Allocate memory for each Tarō's string
    t.append(str(input()))
    # Allocate memory for each Hanako's string
    h.append(str(input()))
    # Compare and update Hanako's score
    if t[i] < h[i]:
        hanako += 3
    # Compare and update Tarō's score
    if t[i] > h[i]:
        taro += 3
    # If strings are equal
    if t[i] == h[i]:
        # Increment Tarō's score by 1
        taro += 1
        # Increment Hanako's score by 1
        hanako += 1

# Print the final scores
print(taro, hanako)

