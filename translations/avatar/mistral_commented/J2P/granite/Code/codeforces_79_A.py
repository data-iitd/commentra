
# Import the necessary Python modules for input/output and string manipulation
import sys

# Define a static method 'canTake' that checks if the required resources are available
def canTake(xNeeded, xAvailable, yNeeded, yAvailable):
    # Check if the required number of units of the x-resource exceeds the available amount
    if xNeeded > xAvailable:
        return False
    # Check if the required number of units of the y-resource exceeds the available amount
    if yNeeded > yAvailable:
        return False
    # If both checks pass, the current turn can take the required resources
    return True

# Define the main method where the game logic is implemented
def main():
    # Initialize the input stream and tokenizer
    input = sys.stdin.read()
    tokens = input.split()

    # Read the initial position of the two players (Hanako and Ciel)
    x = int(tokens[0])
    y = int(tokens[1])

    # Start the game loop
    turn = 0
    while True:
        # Check which player's turn it is
        if turn % 2 == 0: # Hanako's turn
            if canTake(2, x, 2, y): # Try to move Hanako two units to the left and two units up
                x -= 2
                y -= 2
            elif canTake(1, x, 12, y): # Try to move Hanako one unit to the left and twelve units up
                x -= 1
                y -= 12
            else: # If neither move is possible, print "Hanako" and exit the program
                print("Hanako")
                return
        else: # Ciel's turn
            if canTake(0, x, 22, y): # Try to move Ciel two units to the right and twenty-two units down
                y -= 22
            elif canTake(1, x, 12, y): # Try to move Ciel one unit to the right and twelve units down
                x -= 1
                y -= 12
            elif canTake(2, x, 2, y): # Try to move Ciel two units to the right and two units down
                x -= 2
                y -= 2
            else: # If neither move is possible, print "Ciel" and exit the program
                print("Ciel")
                return

        # Increment the turn number
        turn += 1

# Call the main method to start the game
main()
