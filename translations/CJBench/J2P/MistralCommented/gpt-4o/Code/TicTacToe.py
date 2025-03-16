import numpy as np

# Initialize the board as a list
board = [str(i) for i in range(1, 10)]  # initialize the board with numbers 1 to 9
turn = "X"  # set the initial turn to X

def check_winner():
    # Check rows, columns, and diagonals for a win
    winning_combinations = [
        [board[0], board[1], board[2]],  # first row
        [board[3], board[4], board[5]],  # second row
        [board[6], board[7], board[8]],  # third row
        [board[0], board[3], board[6]],  # first column
        [board[1], board[4], board[7]],  # second column
        [board[2], board[5], board[8]],  # third column
        [board[0], board[4], board[8]],  # first diagonal
        [board[2], board[4], board[6]]   # second diagonal
    ]
    
    for combination in winning_combinations:
        if combination == ["X", "X", "X"]:
            return "X"  # return X as the winner
        elif combination == ["O", "O", "O"]:
            return "O"  # return O as the winner

    # Check if all board positions are filled (draw)
    if all(pos not in "123456789" for pos in board):
        return "draw"  # if all positions are filled and no winner was found, return draw

    return None  # no winner yet

def print_board():
    # Print the board
    print("|---|---|---|")
    print(f"| {board[0]} | {board[1]} | {board[2]} |")
    print("|-----------|")
    print(f"| {board[3]} | {board[4]} | {board[5]} |")
    print("|-----------|")
    print(f"| {board[6]} | {board[7]} | {board[8]} |")
    print("|---|---|---|")

def main():
    global turn
    move_count = 0  # initialize move counter
    winner = None

    # Game loop
    while winner is None:
        if move_count < 9:  # check if there are still moves to be made
            move = int(input(f"Player {turn}, enter your move (1-9): "))

            # Validate the user's move
            if move < 1 or move > 9 or board[move - 1] not in "123456789":
                print("Invalid move! Try again.")
                continue

            # Make the move
            board[move - 1] = turn

            # Print the updated board
            print_board()

            # Check for a winner or a draw
            winner = check_winner()

            # Change the turn
            turn = "O" if turn == "X" else "X"

            move_count += 1  # increment the move counter
        else:  # if all moves have been made
            break

    # Print the game result
    if winner == "draw":
        print("It's a draw! Thanks for playing.")
    else:
        print(f"Congratulations! Player {winner} wins!")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
