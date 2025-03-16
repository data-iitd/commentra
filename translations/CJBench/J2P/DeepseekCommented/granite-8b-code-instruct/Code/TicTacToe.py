
import random

board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
turn = "X"
winner = None

def check_winner():
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
    for value in board:
        if value.isdigit():
            return None
    return "draw"

def print_board():
    print("|---|---|---|")
    print("| " + board[0] + " | " + board[1] + " | " + board[2] + " |")
    print("|-----------|")
    print("| " + board[3] + " | " + board[4] + " | " + board[5] + " |")
    print("|-----------|")
    print("| " + board[6] + " | " + board[7] + " | " + board[8] + " |")
    print("|---|---|---|")

move_count = 0
while winner is None:
    if move_count < 9:
        # Prompt the current player to make a move
        move = int(input())
        if move < 1 or move > 9 or not board[move - 1].isdigit():
            print("Invalid move! Try again.")
            continue
        board[move - 1] = turn
        print_board()
        winner = check_winner()
        turn = "X" if turn == "O" else "O"
        move_count += 1
    else:
        break

# Congratulate the winner or inform about a draw
if winner == "draw":
    print("It's a draw! Thanks for playing.")
else:
    print("Congratulations! Player " + winner + " wins!")

