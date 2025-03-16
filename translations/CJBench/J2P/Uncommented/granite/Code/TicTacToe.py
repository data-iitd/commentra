

board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
turn = "X"
winner = None
move_count = 0

def check_winner():
    for a in range(8):
        line = None
        switch (a) {
            case 0:
                line = board[0] + board[1] + board[2]
                break
            case 1:
                line = board[3] + board[4] + board[5]
                break
            case 2:
                line = board[6] + board[7] + board[8]
                break
            case 3:
                line = board[0] + board[3] + board[6]
                break
            case 4:
                line = board[1] + board[4] + board[7]
                break
            case 5:
                line = board[2] + board[5] + board[8]
                break
            case 6:
                line = board[0] + board[4] + board[8]
                break
            case 7:
                line = board[2] + board[4] + board[6]
                break
        }
        if (line.equals("XXX")) return "X"
        if (line.equals("OOO")) return "O"
    for value in board:
        if (value.matches("\\d")) return None 
    return "draw"

def print_board():
    print("|---|---|---|")
    print("| " + board[0] + " | " + board[1] + " | " + board[2] + " |")
    print("|-----------|")
    print("| " + board[3] + " | " + board[4] + " | " + board[5] + " |")
    print("|-----------|")
    print("| " + board[6] + " | " + board[7] + " | " + board[8] + " |")
    print("|---|---|---|")

while winner == None:
    if move_count < 9:
        move = int(input())
        if move < 1 or move > 9 or not board[move - 1].matches("\\d"):
            print("Invalid move! Try again.")
            continue
        board[move - 1] = turn
        print_board()
        winner = check_winner()
        turn = turn if turn == "X" else "O"
        move_count += 1
    else:
        break

if winner.equals("draw"):
    print("It's a draw! Thanks for playing.")
else:
    print("Congratulations! Player " + winner + " wins!")

