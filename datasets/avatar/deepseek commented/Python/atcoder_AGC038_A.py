
import sys

def solve(H: int, W: int, A: int, B: int):
    # Initialize the answer matrix with "0"
    answer = [["0"] * W for _ in range(H)]
    
    # Fill the matrix based on the given conditions
    for i in range(H):
        for j in range(W):
            if i < B:  # Check if the row index is less than B
                if j < A:  # Check if the column index is less than A
                    answer[i][j] = "0"  # Assign "0" if both conditions are met
                else:
                    answer[i][j] = "1"  # Assign "1" otherwise
            else:  # If the row index is not less than B
                if j < A:
                    answer[i][j] = "1"  # Assign "1" if the column index is less than A
                else:
                    answer[i][j] = "0"  # Assign "0" otherwise
    
    # Print each row of the matrix as a string
    for i in range(H):
        print(''.join(answer[i]))
    
    return

def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    
    tokens = iterate_tokens()
    H = int(next(tokens))  # Read the height
    W = int(next(tokens))  # Read the width
    A = int(next(tokens))  # Read the number of columns to be filled with "0"
    B = int(next(tokens))  # Read the number of rows to be filled with "0"
    
    solve(H, W, A, B)  # Call the solve function with the read values

if __name__ == '__main__':
    main()  # Call the main function if the script is run as the main module

