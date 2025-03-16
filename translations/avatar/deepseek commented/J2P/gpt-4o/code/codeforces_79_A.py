import sys

# The can_take function checks if the resources are sufficient to meet the requirements
def can_take(x_needed, x_available, y_needed, y_available):
    if x_needed > x_available: 
        return False  # Check if x_needed is more than x_available
    if y_needed > y_available: 
        return False  # Check if y_needed is more than y_available
    return True  # Return true if both conditions are satisfied

def main():
    # Reading input from standard input
    x, y = map(int, sys.stdin.readline().strip().split())
    turn = 0  # Initializing the turn counter

    # The main loop where the game alternates between two players based on the turn counter
    while True:
        if turn % 2 == 0:  # Check if it's Hanako's turn (even turn)
            # Hanako's turn actions: Attempt to take resources in the given order
            if can_take(2, x, 2, y):  # Attempt to take 2 from both x and y
                x -= 2
                y -= 2
            elif can_take(1, x, 12, y):  # Attempt to take 1 from x and 12 from y
                x -= 1
                y -= 12
            elif can_take(0, x, 22, y):  # Attempt to take 22 from y
                y -= 22
            else:  # If no resources can be taken, Hanako loses
                print("Hanako")
                return
        else:  # It's Ciel's turn (odd turn)
            # Ciel's turn actions: Attempt to take resources in the given order
            if can_take(0, x, 22, y):  # Attempt to take 22 from y
                y -= 22
            elif can_take(1, x, 12, y):  # Attempt to take 1 from x and 12 from y
                x -= 1
                y -= 12
            elif can_take(2, x, 2, y):  # Attempt to take 2 from both x and y
                x -= 2
                y -= 2
            else:  # If no resources can be taken, Ciel loses
                print("Ciel")
                return
        turn += 1  # Increment the turn counter

if __name__ == "__main__":
    main()

# <END-OF-CODE>
