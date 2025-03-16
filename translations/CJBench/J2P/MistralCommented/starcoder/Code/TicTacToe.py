
import sys

# initialize the board as a String array
board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]

# keep track of whose turn it is
turn = "X"

# check rows for a win
def checkWinner():
    for a in range(0, 8):
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
        # check if the line contains three identical symbols (X or O)
        if line == "XXX":
            return "X" # return X as the winner
        elif line == "OOO":
            return "O" # return O as the winner
    # check if all the board positions are filled (draw)
    for value in board:
        if value.matches("\\d"): continue # skip empty positions
        return None # if all positions are filled, return null
    return "draw" # if all positions are filled and no winner was found, return draw

# print the board header
def printBoard():
    print("|---|---|---|")
    # print the board rows
    print("| " + board[0] + " | " + board[1] + " | " + board[2] + " |")
    print("|-----------|")
    print("| " + board[3] + " | " + board[4] + " | " + board[5] + " |")
    print("|-----------|")
    print("| " + board[6] + " | " + board[7] + " | " + board[8] + " |")
    # print the board footer
    print("|---|---|---|")

# game loop
while True:
    # check if there are still moves to be made
    if len(board) > 0:
        # get the user's move
        move = input("Player " + turn + ", enter your move (1-9): ")
        # validate the user's move
        if move < 1 or move > 9 or not board[move - 1].matches("\\d"):
            print("Invalid move! Try again.")
            continue
        # make the move
        board[move - 1] = turn
        # print the updated board
        printBoard()
        # check for a winner or a draw
        winner = checkWinner()
        # change the turn
        turn = turn.equals("X")? "O" : "X"
    else:
        break
    # print the game result
    if winner.equals("draw"):
        print("It's a draw! Thanks for playing.")
    else:
        print("Congratulations! Player " + winner + " wins!")

# close the Scanner
sys.stdin.close()

