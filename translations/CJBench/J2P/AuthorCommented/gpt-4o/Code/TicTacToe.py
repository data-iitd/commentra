# A simple program to demonstrate
# Tic-Tac-Toe Game.

def check_winner(board):
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
        if line == "XXX":
            return "X"
        if line == "OOO":
            return "O"

    # Check for a draw
    if all(not value.isdigit() for value in board):
        return "draw"

    return None  # Game not over yet


def print_board(board):
    print("|---|---|---|")
    print("| " + board[0] + " | " + board[1] + " | " + board[2] + " |")
    print("|-----------|")
    print("| " + board[3] + " | " + board[4] + " | " + board[5] + " |")
    print("|-----------|")
    print("| " + board[6] + " | " + board[7] + " | " + board[8] + " |")
    print("|---|---|---|")


def main():
    board = [str(i + 1) for i in range(9)]
    turn = "X"
    winner = None

    move_count = 0  # Count the number of moves made
    while winner is None:
        if move_count < 9:
            move = int(input("Player " + turn + ", enter your move (1-9): "))
            if move < 1 or move > 9 or not board[move - 1].isdigit():
                print("Invalid move! Try again.")
                continue
            board[move - 1] = turn
            print_board(board)
            winner = check_winner(board)
            turn = "O" if turn == "X" else "X"
            move_count += 1
        else:
            break

    if winner == "draw":
        print("It's a draw! Thanks for playing.")
    else:
        print("Congratulations! Player " + winner + " wins!")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
