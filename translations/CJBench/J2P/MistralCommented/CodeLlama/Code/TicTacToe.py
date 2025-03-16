
board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
turn = "X"

def check_winner():
    # check rows for a win
    for a in range(8):
        line = None
        if a == 0:
            line = board[0] + board[1] + board[2]
        elif a == 1:
            line = board[3] + board[4] + board[5]
        elif a == 2:
            line = board[6] + board[7] + board[8]
        elif a == 3:
            line = board[0] + board[3] + board[6]
        elif a == 4:
            line = board[1] + board[4] + board[7]
        elif a == 5:
            line = board[2] + board[5] + board[8]
        elif a == 6:
            line = board[0] + board[4] + board[8]
        elif a == 7:
            line = board[2] + board[4] + board[6]
        if line == "XXX":
            return "X"
        elif line == "OOO":
            return "O"
    # check if all the board positions are filled (draw)
    for value in board:
        if value.isdigit():
            continue
        return None
    return "draw"

def print_board():
    # print the board header
    print("|---|---|---|")
    # print the board rows
    print("| " + board[0] + " | " + board[1] + " | " + board[2] + " |")
    print("|-----------|")
    print("| " + board[3] + " | " + board[4] + " | " + board[5] + " |")
    print("|-----------|")
    print("| " + board[6] + " | " + board[7] + " | " + board[8] + " |")
    # print the board footer
    print("|---|---|---|")

winner = None
move_count = 0

# game loop
while winner == None:
    if move_count < 9:
        move = int(input("Player " + turn + ", enter your move (1-9):"))

        # validate the user's move
        if move < 1 or move > 9 or not board[move - 1].isdigit():
            print("Invalid move! Try again.")
            continue

        # make the move
        board[move - 1] = turn

        # print the updated board
        print_board()

        # check for a winner or a draw
        winner = check_winner()

        # change the turn
        turn = "O" if turn == "X" else "X"

        move_count += 1
    else:
        break

# print the game result
if winner == "draw":
    print("It's a draw! Thanks for playing.")
else:
    print("Congratulations! Player " + winner + " wins!")

# 