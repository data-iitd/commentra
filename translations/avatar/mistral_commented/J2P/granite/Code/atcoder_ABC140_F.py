

import sys

# Read the number of slimes N from user input
N = int(input())
# Calculate the size of the array S based on N
size = 1 << N
# Initialize the array S with user input
S = [int(x) for x in input().split()]
# Initialize a boolean array spawned to keep track of which slimes have been spawned
spawned = [False] * size
# Set the last element of spawned to true, as it represents the position of the last slime
spawned[-1] = True

# Sort the array S in ascending order
S.sort()

# Initialize an ArrayList named active to store the indices of the currently active slimes
active = [size - 1]
# Set the last element of spawned to true and add its index to the active list
spawned[-1] = True

# Iterate through each generation of slimes
for i in range(N):
    # Sort the ArrayList active in descending order
    active.sort(reverse=True)

    # Initialize an ArrayList named activated to store the indices of the slimes that will be activated in the next generation
    activated = []
    # Initialize a variable named next to keep track of the index of the current slime in array S
    next = size - 1

    # Iterate through each slime in the current generation
    for slime in active:
        # While the current index next is greater than or equal to 0 and the slime size is greater than or equal to the size of the current slime or the current index has already been spawned
        while next >= 0 and (S[next] >= slime or spawned[next]):
            next -= 1
        # If the current index next is less than 0, it means that there is no empty space for the new slime to spawn, so print "No" and exit the program
        if next < 0:
            print("No")
            sys.exit()
        # Set the current index as spawned and add its index to the activated ArrayList
        spawned[next] = True
        activated.append(S[next])

    # Add all the indices of the activated slimes to the active ArrayList
    active.extend(activated)

# Print "Yes" to indicate that the program has successfully determined the positions of all N slimes
print("Yes")
