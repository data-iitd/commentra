
import random

# Array to represent the Tic-Tac-Toe board
board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
# Variable to track the current player's turn
turn = "X"

# Method to check for a winner or a draw
def check_winner():
    # Check all possible winning combinations
    for a in range(8):
        line = None
        if a == 0:
            line = board[0] + board[1] + board[2]  # Top row
        elif a == 1:
            line = board[3] + board[4] + board[5]  # Middle row
        elif a == 2:
            line = board[6] + board[7] + board[8]  # Bottom row
        elif a == 3:
            line = board[0] + board[3] + board[6]  # Left column
        elif a == 4:
            line = board[1] + board[4] + board[7]  # Middle column
        elif a == 5:
            line = board[2] + board[5] + board[8]  # Right column
        elif a == 6:
            line = board[0] + board[4] + board[8]  # Diagonal from top-left to bottom-right
        elif a == 7:
            line = board[2] + board[4] + board[6]  # Diagonal from top-right to bottom-left
        # Check if player X has won
        if line == "XXX":
            return "X"
        # Check if player O has won
        if line == "OOO":
            return "O"
    # Check for any remaining moves on the board
    for value in board:
        if value.isdigit():
            return None  # If there's still a number, the game is not over
    # If no moves left and no winner, it's a draw
    return "draw"

# Method to print the current state of the board
def print_board():
    print("|---|---|---|")
    print("| " + board[0] + " | " + board[1] + " | " + board[2] + " |")
    print("|-----------|")
    print("| " + board[3] + " | " + board[4] + " | " + board[5] + " |")
    print("|-----------|")
    print("| " + board[6] + " | " + board[7] + " | " + board[8] + " |")
    print("|---|---|---|")

# Main method to run the Tic-Tac-Toe game
def main():
    import sys
    # Initialize the board with numbers 1-9
    board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
    turn = "X"  # X starts first
    winner = None

    # Fill the board with numbers representing empty spaces
    for a in range(9):
        board[a] = str(a + 1)

    move_count = 0  # Counter for the number of moves made
    # Loop until there is a winner or the board is full
    while winner is None:
        if move_count < 9:
            # Read the player's move
            move = int(input("Player " + turn + ", enter your move (1-9): "))
            # Validate the move
            if move < 1 or move > 9 or not board[move - 1].isdigit():
                print("Invalid move! Try again.")
                continue  # Prompt for a new move
            # Update the board with the current player's move
            board[move - 1] = turn
            # Print the updated board
            print_board()
            # Check for a winner after the move
            winner = check_winner()
            # Switch turns between players
            turn = "O" if turn == "X" else "X"
            move_count += 1  # Increment the move counter
        else:
            break  # Exit if the board is full

    # Announce the result of the game
    if winner == "draw":
        print("It's a draw! Thanks for playing.")
    else:
        print("Congratulations! Player " + winner + " wins!")

if __name__ == "__main__":
    main()
