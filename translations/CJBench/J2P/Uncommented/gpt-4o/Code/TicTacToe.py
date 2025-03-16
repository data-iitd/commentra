import numpy as np

def check_winner(board):
    for a in range(8):
        if a < 3:  # Rows
            line = board[a * 3:(a + 1) * 3]
        elif a < 6:  # Columns
            line = [board[a % 3 + i * 3] for i in range(3)]
        else:  # Diagonals
            if a == 6:
                line = [board[0], board[4], board[8]]
            else:
                line = [board[2], board[4], board[6]]
        
        if line == ['X', 'X', 'X']:
            return 'X'
        if line == ['O', 'O', 'O']:
            return 'O'
    
    if all(not cell.isdigit() for cell in board):
        return 'draw'
    
    return None

def print_board(board):
    print("|---|---|---|")
    print(f"| {board[0]} | {board[1]} | {board[2]} |")
    print("|-----------|")
    print(f"| {board[3]} | {board[4]} | {board[5]} |")
    print("|-----------|")
    print(f"| {board[6]} | {board[7]} | {board[8]} |")
    print("|---|---|---|")

def main():
    board = [str(i + 1) for i in range(9)]
    turn = 'X'
    winner = None
    move_count = 0
    
    while winner is None:
        if move_count < 9:
            print_board(board)
            move = int(input("Enter your move (1-9): "))
            if move < 1 or move > 9 or not board[move - 1].isdigit():
                print("Invalid move! Try again.")
                continue
            
            board[move - 1] = turn
            winner = check_winner(board)
            turn = 'O' if turn == 'X' else 'X'
            move_count += 1
        else:
            break
    
    if winner == 'draw':
        print("It's a draw! Thanks for playing.")
    else:
        print(f"Congratulations! Player {winner} wins!")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
