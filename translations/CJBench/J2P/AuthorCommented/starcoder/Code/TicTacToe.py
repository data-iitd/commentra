# A simple program to demonstrate
# Tic-Tac-Toe Game.
import java.util.*;

def checkWinner():
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

        # Check for a winner
        if line.equals("XXX"): return "X"
        if line.equals("OOO"): return "O"

    # Check for a draw
    for value in board:
        if value.matches("\\d"): return None # Game not over yet

    return "draw"

def printBoard():
    print("|---|---|---|")
    print("| " + board[0] + " | " + board[1] + " | " + board[2] + " |")
    print("|-----------|")
    print("| " + board[3] + " | " + board[4] + " | " + board[5] + " |")
    print("|-----------|")
    print("| " + board[6] + " | " + board[7] + " | " + board[8] + " |")
    print("|---|---|---|")

if __name__ == "__main__":
    board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
    turn = "X"
    winner = None

    # Initialize the board
    for a in range(9):
        board[a] = str(a + 1)

    moveCount = 0 # Count the number of moves made
    while winner == None:
        if moveCount < 9:
            move = int(input())
            if move < 1 or move > 9 or not board[move - 1].matches("\\d"):
                print("Invalid move! Try again.")
                continue
            board[move - 1] = turn
            printBoard()
            winner = checkWinner()
            turn = turn.equals("X")? "O" : "X"
            moveCount += 1
        else:
            break

    if winner.equals("draw"):
        print("It's a draw! Thanks for playing.")
    else:
        print("Congratulations! Player " + winner + " wins!")

