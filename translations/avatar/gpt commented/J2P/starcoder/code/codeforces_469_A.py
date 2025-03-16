
# <START-OF-CODE>

# Create a Scanner object to read input from the console
sc = Scanner(sys.stdin)

# Read the number of players (n) and the number of levels (levels)
n = sc.nextInt()
levels = sc.nextInt()

# Initialize variables to keep track of sums and counts
sum = 0
sum2 = 0
sum3 = 0

# Create an array to store the levels completed by the first player
arr = [0] * levels
count = 0

# Read the levels completed by the first player
for i in range(levels):
    arr[i] = sc.nextInt()

# Read the number of additional levels completed by the second player
level2 = sc.nextInt()

# Calculate the total number of levels completed by both players
level3 = levels + level2

# Create a new array to store levels completed by both players
arr2 = [0] * level3

# Copy levels from the first player's array to the new array
for i in range(arr.length):
    arr2[i] = arr[i]

# Read the levels completed by the second player and add them to the new array
for i in range(arr.length, level3):
    arr2[i] = sc.nextInt()

# Create an array to represent all levels (1 to n)
arr3 = [0] * n
j = 0

# Fill arr3 with level numbers from 1 to n
for i in range(n):
    arr3[i] = ++j

# Check how many levels from arr3 are completed by either player
for i in range(n):
    for x in range(arr2.length):
        # If a level is found in arr2, increment the count and break
        if arr3[i] == arr2[x]:
            count += 1
            break

# Determine if all levels have been completed by at least one player
if count == n:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")

# 