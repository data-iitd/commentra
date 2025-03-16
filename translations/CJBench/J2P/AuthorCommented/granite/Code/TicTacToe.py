
# A simple program to demonstrate
# Tic-Tac-Toe Game.
import sys

board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
turn = "X"
winner = None

# Initialize the board

# Count the number of moves made
moveCount = 0

while winner == None:
    if moveCount < 9:
        move = int(input())
        if move < 1 or move > 9 or board[move - 1]!= str(move):
            print("Invalid move! Try again.")
            continue
        board[move - 1] = turn
        print("|---|---|---|")
        print("| " + board[0] + " | " + board[1] + " | " + board[2] + " |")
        print("|-----------|")
        print("| " + board[3] + " | " + board[4] + " | " + board[5] + " |")
        print("|-----------|")
        print("| " + board[6] + " | " + board[7] + " | " + board[8] + " |")
        print("|---|---|---|")
        winner = checkWinner()
        turn = "X" if turn == "O" else "O"
        moveCount += 1
    else:
        break

if winner == "draw":
    print("It's a draw! Thanks for playing.")
else:
    print("Congratulations! Player " + winner + " wins!")

sys.exit()
