def can_take(x_needed, x_available, y_needed, y_available):
    # Check if the needed x resources are greater than available
    if x_needed > x_available:
        return False
    # Check if the needed y resources are greater than available
    if y_needed > y_available:
        return False
    # If both checks pass, return true
    return True

def main():
    # Read input values for x and y
    x, y = map(int, input().split())
    turn = 0  # Initialize turn counter

    # Infinite loop to alternate turns between two players
    while True:
        # Check if it's the first player's turn (even turn number)
        if turn % 2 == 0:
            # Try to take resources according to the defined rules
            if can_take(2, x, 2, y):
                x -= 2  # Deduct resources for the first option
                y -= 2
            elif can_take(1, x, 12, y):
                x -= 1  # Deduct resources for the second option
                y -= 12
            elif can_take(0, x, 22, y):
                y -= 22  # Deduct resources for the third option
            else:
                # If no options are available, first player loses
                print("Hanako")
                return
        else:
            # Check if it's the second player's turn (odd turn number)
            if can_take(0, x, 22, y):
                y -= 22  # Deduct resources for the first option
            elif can_take(1, x, 12, y):
                x -= 1  # Deduct resources for the second option
                y -= 12
            elif can_take(2, x, 2, y):
                x -= 2  # Deduct resources for the third option
                y -= 2
            else:
                # If no options are available, second player loses
                print("Ciel")
                return
        turn += 1  # Increment turn counter for the next iteration

if __name__ == "__main__":
    main()

# <END-OF-CODE>
