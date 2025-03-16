board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
turn = "X"

def print_board():
    print("|---|---|---|")
    print("| {} | {} | {} |".format(board[0], board[1], board[2]))
    print("|-----------|")
    print("| {} | {} | {} |".format(board[3], board[4], board[5]))
    print("|-----------|")
    print("| {} | {} | {} |".format(board[6], board[7], board[8]))
    print("|---|---|---|")

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
        elif line == "OOO":
            return "O"
    if all(cell.isdigit() for cell in board):
        return "draw"
    return None

while True:
    print_board()
    move = int(input("Player {}, enter your move (1-9): ".format(turn))) - 1
    if board[move] not in "XO":
        board[move] = turn
        winner = check_winner()
        if winner:
            print_board()
            if winner == "draw":
                print("It's a draw! Thanks for playing.")
            else:
                print("Congratulations! Player {} wins!".format(winner))
            break
        turn = "O" if turn == "X" else "X"
    else:
        print("Invalid move! Try again.")
