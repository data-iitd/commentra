
# <START-OF-CODE>

# Create a Scanner object to read input from the user
sc = Scanner(sys.stdin)

# Read the number of boxes (N) and the number of moves (M)
N = sc.nextInt()
M = sc.nextInt()

# Initialize an array of Box objects
B = []

# Create the first box as red and the rest as not red
B.append(Box(1, True))
for i in range(1, N):
    B.append(Box(1, False))

# Process M moves based on user input
for i in range(0, M):
    # Read the indices of the boxes to move from and to
    x = sc.nextInt() - 1
    y = sc.nextInt() - 1
    # Move the contents from box x to box y
    B[x].moveTo(B[y])

# Count the number of red boxes after all moves
counter = 0
for b in B:
    if b.red:
        counter += 1

# Output the count of red boxes
print(counter)

# 