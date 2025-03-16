# A simple program to demonstrate
# Tic-Tac-Toe Game.

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

    # Check for a draw
    if all(cell.isdigit() for cell in board):
        return None  # Game not over yet

    return "draw"

def print_board():
    print("|---|---|---|")
    print("| {} | {} | {} |".format(board[0], board[1], board[2]))
    print("|-----------|")
    print("| {} | {} | {} |".format(board[3], board[4], board[5]))
    print("|-----------|")
    print("| {} | {} | {} |".format(board[6], board[7], board[8]))
    print("|---|---|---|")

board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
turn = "X"
winner = None

# Initialize the board
for i in range(9):
    board[i] = str(i + 1)

move_count = 0  # Count the number of moves made
while winner is None:
    if move_count < 9:
        move = int(input())
        if move < 1 or move > 9 or not board[move - 1].isdigit():
            print("Invalid move! Try again.")
            continue
        board[move - 1] = turn
        print_board()
        winner = check_winner()
        turn = "O" if turn == "X" else "X"
        move_count += 1
    else:
        break

if winner == "draw":
    print("It's a draw! Thanks for playing.")
else:
    print("Congratulations! Player {} wins!".format(winner))
