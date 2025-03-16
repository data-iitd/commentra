import numpy as np

# Function to check for a winner or a draw
def check_winner(board):
    # Check all possible winning combinations
    for a in range(8):
        if a < 3:  # Top, middle, bottom rows
            line = board[a, :].tostring()
        elif a < 6:  # Left, middle, right columns
            line = board[:, a - 3].tostring()
        else:  # Diagonals
            if a == 6:
                line = board.diagonal().tostring()
            else:
                line = np.fliplr(board).diagonal().tostring()

        # Check if player X has won
        if line == b'XXX':
            return 'X'
        # Check if player O has won
        if line == b'OOO':
            return 'O'

    # Check for any remaining moves on the board
    if np.any(np.char.isnumeric(board)):
        return None  # If there's still a number, the game is not over

    # If no moves left and no winner, it's a draw
    return 'draw'

# Function to print the current state of the board
def print_board(board):
    print("|---|---|---|")
    for row in board:
        print("| " + " | ".join(row) + " |")
        print("|-----------|")
    print("|---|---|---|")

# Main function to run the Tic-Tac-Toe game
def main():
    # Initialize the board with numbers 1-9
    board = np.array([[str(i + 1) for i in range(3)],
                      [str(i + 4) for i in range(3)],
                      [str(i + 7) for i in range(3)]])
    turn = 'X'  # X starts first
    winner = None

    move_count = 0  # Counter for the number of moves made
    # Loop until there is a winner or the board is full
    while winner is None:
        if move_count < 9:
            # Read the player's move
            move = int(input("Player " + turn + ", enter your move (1-9): "))
            # Validate the move
            if move < 1 or move > 9 or board[(move - 1) // 3, (move - 1) % 3] not in [str(i) for i in range(1, 10)]:
                print("Invalid move! Try again.")
                continue  # Prompt for a new move

            # Update the board with the current player's move
            board[(move - 1) // 3, (move - 1) % 3] = turn
            # Print the updated board
            print_board(board)
            # Check for a winner after the move
            winner = check_winner(board)
            # Switch turns between players
            turn = 'O' if turn == 'X' else 'X'
            move_count += 1  # Increment the move counter
        else:
            break  # Exit if the board is full

    # Announce the result of the game
    if winner == 'draw':
        print("It's a draw! Thanks for playing.")
    else:
        print("Congratulations! Player " + winner + " wins!")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
