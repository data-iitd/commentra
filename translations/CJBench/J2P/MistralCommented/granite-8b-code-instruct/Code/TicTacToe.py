

board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"] # initialize the board as a list of strings
turn = "X" # keep track of whose turn it is

def check_winner():
    # check rows for a win
    for a in range(8):
        line = None
        if a == 0:
            line = board[0] + board[1] + board[2] # concatenate the strings of the first row
        elif a == 1:
            line = board[3] + board[4] + board[5] # concatenate the strings of the second row
        elif a == 2:
            line = board[6] + board[7] + board[8] # concatenate the strings of the third row
        elif a == 3:
            line = board[0] + board[3] + board[6] # concatenate the strings of the first and third diagonal
        elif a == 4:
            line = board[1] + board[4] + board[7] # concatenate the strings of the second diagonal
        elif a == 5:
            line = board[2] + board[5] + board[8] # concatenate the strings of the third diagonal
        elif a == 6:
            line = board[0] + board[4] + board[8] # concatenate the strings of the first and third column
        elif a == 7:
            line = board[2] + board[4] + board[6] # concatenate the strings of the second and third column
        # check if the line contains three identical symbols (X or O)
        if line == "XXX":
            return "X" # return X as the winner
        elif line == "OOO":
            return "O" # return O as the winner
    # check if all the board positions are filled (draw)
    for value in board:
        if value.isdigit(): continue # skip empty positions
        return None # if all positions are filled, return None
    return "draw" # if all positions are filled and no winner was found, return draw

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

if __name__ == "__main__":
    import sys # import the sys module
    board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"] # initialize the board as a list of strings
    turn = "X" # set the initial turn to X
    move_count = 0 # initialize move counter

    # game loop
    while True:
        if move_count < 9: # check if there are still moves to be made
            move = None # variable to store the user's move

            # get the user's move
            print("Player " + turn + ", enter your move (1-9):", end=" ")
            move = sys.stdin.readline().strip()

            # validate the user's move
            if not move.isdigit() or int(move) < 1 or int(move) > 9 or board[int(move) - 1]!= "1":
                print("Invalid move! Try again.")
                continue
            # make the move
            board[int(move) - 1] = turn

            # print the updated board
            print_board()

            # check for a winner or a draw
            winner = check_winner()

            # change the turn
            turn = "X" if turn == "O" else "O"

            move_count += 1 # increment the move counter
        else: # if all moves have been made
            break

    # print the game result
    if winner == "draw":
        print("It's a draw! Thanks for playing.")
    else:
        print("Congratulations! Player " + winner + " wins!")

