def print_board(board):
    print("|---|---|---|")
    print("| {} | {} | {} |".format(board[0], board[1], board[2]))
    print("|-----------|")
    print("| {} | {} | {} |".format(board[3], board[4], board[5]))
    print("|-----------|")
    print("| {} | {} | {} |".format(board[6], board[7], board[8]))
    print("|---|---|---|")

def check_winner(board):
    # Check all possible winning combinations
    winning_combinations = [
        board[0] + board[1] + board[2],  # Top row
        board[3] + board[4] + board[5],  # Middle row
        board[6] + board[7] + board[8],  # Bottom row
        board[0] + board[3] + board[6],  # Left column
        board[1] + board[4] + board[7],  # Middle column
        board[2] + board[5] + board[8],  # Right column
        board[0] + board[4] + board[8],  # Diagonal from top-left to bottom-right
        board[2] + board[4] + board[6]   # Diagonal from top-right to bottom-left
    ]
    
    # Check if player X has won
    if 'XXX' in winning_combinations:
        return 'X'
    # Check if player O has won
    if 'OOO' in winning_combinations:
        return 'O'
    # Check for any remaining moves on the board
    for cell in board:
        if cell.isdigit():
            return None  # If there's still a number, the game is not over
    # If no moves left and no winner, it's a draw
    return 'draw'

def main():
    # Initialize the board with numbers 1-9
    board = [str(i + 1) for i in range(9)]
    turn = 'X'  # X starts first
    winner = None

    # Loop until there is a winner or the board is full
    while winner is None:
        print_board(board)
        # Read the player's move
        move = int(input()) - 1
        # Validate the move
        if move < 0 or move > 8 or not board[move].isdigit():
            print("Invalid move! Try again.")
            continue  # Prompt for a new move
        # Update the board with the current player's move
        board[move] = turn
        # Check for a winner after the move
        winner = check_winner(board)
        # Switch turns between players
        turn = 'O' if turn == 'X' else 'X'

    # Print the final board state
    print_board(board)
    # Announce the result of the game
    if winner == 'draw':
        print("It's a draw! Thanks for playing.")
    else:
        print("Congratulations! Player {} wins!".format(winner))

if __name__ == "__main__":
    main()
