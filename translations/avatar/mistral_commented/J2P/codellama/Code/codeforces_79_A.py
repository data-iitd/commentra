# Import the necessary Python modules for input/output and string manipulation
import sys

# Define a function 'can_take' that checks if the required resources are available
def can_take(x_needed, x_available, y_needed, y_available):
    # Check if the required number of units of the x-resource exceeds the available amount
    if x_needed > x_available:
        return False

    # Check if the required number of units of the y-resource exceeds the available amount
    if y_needed > y_available:
        return False

    # If both checks pass, the current turn can take the required resources
    return True

# Define the main function where the game logic is implemented
def main():
    # Initialize the input stream and tokenizer
    br = sys.stdin
    st = br.readline().split()

    # Read the initial position of the two players (Hanako and Ciel)
    x = int(st[0])
    y = int(st[1])

    # Start the game loop
    turn = 0
    while True:
        # Check which player's turn it is
        if turn % 2 == 0: # Hanako's turn
            if can_take(2, x, 2, y): # Try to move Hanako two units to the left and two units up
                x -= 2
                y -= 2
            elif can_take(1, x, 12, y): # Try to move Hanako one unit to the left and twelve units up
                x -= 1
                y -= 12
            else: # If neither move is possible, print "Hanako" and exit the program
                print("Hanako")
                return
        else: # Ciel's turn
            if can_take(0, x, 22, y): # Try to move Ciel two units to the right and twenty-two units down
                y -= 22
            elif can_take(1, x, 12, y): # Try to move Ciel one unit to the right and twelve units down
                x -= 1
                y -= 12
            elif can_take(2, x, 2, y): # Try to move Ciel two units to the right and two units down
                x -= 2
                y -= 2
            else: # If neither move is possible, print "Ciel" and exit the program
                print("Ciel")
                return

        # Increment the turn number
        turn += 1

# Call the main function
main()

