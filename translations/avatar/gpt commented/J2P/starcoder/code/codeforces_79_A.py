
# Method to check if the required resources can be taken
def canTake(xNeeded, xAvailable, yNeeded, yAvailable):
    # Check if the needed x resources are greater than available
    if xNeeded > xAvailable:
        return False
    # Check if the needed y resources are greater than available
    if yNeeded > yAvailable:
        return False
    # If both checks pass, return true
    return True

# Initialize BufferedReader to read input
import sys
import io

br = io.BufferedReader(sys.stdin)
# Tokenize the input line to extract x and y values
st = br.readline().split()
x = int(st[0]) # Parse x value
y = int(st[1]) # Parse y value
turn = 0 # Initialize turn counter

# Infinite loop to alternate turns between two players
while True:
    # Check if it's the first player's turn (even turn number)
    if turn % 2 == 0:
        # Try to take resources according to the defined rules
        if canTake(2, x, 2, y):
            x -= 2 # Deduct resources for the first option
            y -= 2
        elif canTake(1, x, 12, y):
            x -= 1 # Deduct resources for the second option
            y -= 12
        elif canTake(0, x, 22, y):
            y -= 22 # Deduct resources for the third option
        else:
            # If no options are available, first player loses
            print("Hanako")
            return
    else:
        # Check if it's the second player's turn (odd turn number)
        if canTake(0, x, 22, y):
            y -= 22 # Deduct resources for the first option
        elif canTake(1, x, 12, y):
            x -= 1 # Deduct resources for the second option
            y -= 12
        elif canTake(2, x, 2, y):
            x -= 2 # Deduct resources for the third option
            y -= 2
        else:
            # If no options are available, second player loses
            print("Ciel")
            return
    turn += 1 # Increment turn counter for the next iteration

# 