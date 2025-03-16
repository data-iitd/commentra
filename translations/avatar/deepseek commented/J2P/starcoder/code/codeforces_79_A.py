import sys

# The canTake method checks if the resources are sufficient to meet the requirements
def canTake(xNeeded, xAvailable, yNeeded, yAvailable):
    if xNeeded > xAvailable: return False # Check if xNeeded is more than xAvailable
    if yNeeded > yAvailable: return False # Check if yNeeded is more than yAvailable
    return True # Return true if both conditions are satisfied

# The main function where the game is played
def main():
    x, y = map(int, sys.stdin.readline().split()) # Read the input and parse it into x and y
    turn = 0 # Initialize the turn counter

    # The main loop where the game alternates between two players based on the turn counter
    while True:
        if turn % 2 == 0: # Check if it's Hanako's turn (even turn)
            # Hanako's turn actions: Attempt to take resources in the given order
            if canTake(2, x, 2, y): # Attempt to take 2 from both x and y
                x -= 2
                y -= 2
            elif canTake(1, x, 12, y): # Attempt to take 1 from x and 12 from y
                x -= 1
                y -= 12
            elif canTake(0, x, 22, y): # Attempt to take 22 from y
                y -= 22
            else: # If no resources can be taken, Hanako loses
                print("Hanako")
                return
        else: # It's Ciel's turn (odd turn)
            # Ciel's turn actions: Attempt to take resources in the given order
            if canTake(0, x, 22, y): # Attempt to take 22 from y
                y -= 22
            elif canTake(1, x, 12, y): # Attempt to take 1 from x and 12 from y
                x -= 1
                y -= 12
            elif canTake(2, x, 2, y): # Attempt to take 2 from both x and y
                x -= 2
                y -= 2
            else: # If no resources can be taken, Ciel loses
                print("Ciel")
                return
        turn += 1 # Increment the turn counter

if __name__ == "__main__":
    main()

# 