import sys

# Check for a winner based on all possible winning combinations
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
        if line == "XXX":
            return "X"
        elif line == "OOO":
            return "O"
    for value in board:
        if value.isdigit():
            return None
    return "draw"

# Print the current state of the board
def printBoard():
    print("|---|---|---|")
    print("| " + board[0] + " | " + board[1] + " | " + board[2] + " |")
    print("|-----------|")
    print("| " + board[3] + " | " + board[4] + " | " + board[5] + " |")
    print("|-----------|")
    print("| " + board[6] + " | " + board[7] + " | " + board[8] + " |")
    print("|---|---|---|")

# Initialize the board with numbers 1 to 9
def initBoard():
    for a in range(9):
        board[a] = str(a + 1)

# Main function
def main():
    # Initialize the board
    initBoard()
    # Initialize the player turn
    turn = "X"
    # Initialize the winner
    winner = None
    # Initialize the move count
    moveCount = 0

    while winner == None:
        if moveCount < 9:
            # Prompt the current player to make a move
            move = int(input("Player " + turn + ", enter your move: "))
            if move < 1 or move > 9 or not board[move - 1].isdigit():
                print("Invalid move! Try again.")
                continue
            board[move - 1] = turn
            printBoard()
            winner = checkWinner()
            turn = "X" if turn == "O" else "O"
            moveCount += 1
        else:
            break

    # Congratulate the winner or inform about a draw
    if winner == "draw":
        print("It's a draw! Thanks for playing.")
    else:
        print("Congratulations! Player " + winner + " wins!")

# Entry point
if __name__ == "__main__":
    # Initialize the board
    board = [None] * 9
    # Call the main function
    main()

# 