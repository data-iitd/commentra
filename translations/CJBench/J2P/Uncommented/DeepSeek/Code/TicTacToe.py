def check_winner():
    lines = [
        board[0] + board[1] + board[2],
        board[3] + board[4] + board[5],
        board[6] + board[7] + board[8],
        board[0] + board[3] + board[6],
        board[1] + board[4] + board[7],
        board[2] + board[5] + board[8],
        board[0] + board[4] + board[8],
        board[2] + board[4] + board[6]
    ]
    for line in lines:
        if line == "XXX":
            return "X"
        if line == "OOO":
            return "O"
    for value in board:
        if value.isdigit():
            return None
    return "draw"


def print_board():
    print("|---|---|---|")
    print("| {} | {} | {} |".format(board[0], board[1], board[2]))
    print("|-----------|")
    print("| {} | {} | {} |".format(board[3], board[4], board[5]))
    print("|-----------|")
    print("| {} | {} | {} |".format(board[6], board[7], board[8]))
    print("|---|---|---|")


board = [str(i + 1) for i in range(9)]
turn = "X"
winner = None
move_count = 0

while winner is None:
    if move_count < 9:
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

if winner == "draw":
    print("It's a draw! Thanks for playing.")
else:
    print("Congratulations! Player {} wins!".format(winner))
