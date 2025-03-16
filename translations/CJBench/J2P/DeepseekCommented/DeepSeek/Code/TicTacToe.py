board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
turn = "X"
winner = None

# Check for a winner based on all possible winning combinations
def check_winner():
    winning_combinations = [
        board[0] + board[1] + board[2],
        board[3] + board[4] + board[5],
        board[6] + board[7] + board[8],
        board[0] + board[3] + board[6],
        board[1] + board[4] + board[7],
        board[2] + board[5] + board[8],
        board[0] + board[4] + board[8],
        board[2] + board[4] + board[6]
    ]
    for combo in winning_combinations:
        if combo == "XXX":
            return "X"
        if combo == "OOO":
            return "O"
    for cell in board:
        if cell.isdigit():
            return None
    return "draw"

# Print the current state of the board
def print_board():
    print("|---|---|---|")
    print("| {} | {} | {} |".format(board[0], board[1], board[2]))
    print("|-----------|")
    print("| {} | {} | {} |".format(board[3], board[4], board[5]))
    print("|-----------|")
    print("| {} | {} | {} |".format(board[6], board[7], board[8]))
    print("|---|---|---|")

# Main game loop
while winner is None:
    if move_count < 9:
        # Prompt the current player to make a move
        move = int(input()) - 1
        if move < 0 or move > 8 or not board[move].isdigit():
            print("Invalid move! Try again.")
            continue
        board[move] = turn
        print_board()
        winner = check_winner()
        turn = "O" if turn == "X" else "X"
        move_count += 1
    else:
        break

# Congratulate the winner or inform about a draw
if winner == "draw":
    print("It's a draw! Thanks for playing.")
else:
    print("Congratulations! Player {} wins!".format(winner))
