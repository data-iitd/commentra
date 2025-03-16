import sys

def solve(H: int, W: int, A: int, B: int):
    # Initialize a 2D list (matrix) with dimensions H x W filled with "0"
    answer = [["0"] * W for _ in range(H)]
    
    # Fill the matrix based on the conditions involving A and B
    for i in range(H):
        for j in range(W):
            # If we are in the first B rows
            if i < B:
                # If we are in the first A columns
                if j < A:
                    answer[i][j] = "0"  # Set to "0"
                else:
                    answer[i][j] = "1"  # Set to "1" for columns >= A
            else:
                # If we are in rows >= B
                if j < A:
                    answer[i][j] = "1"  # Set to "1" for columns < A
                else:
                    answer[i][j] = "0"  # Set to "0" for columns >= A

    # Print the resulting matrix row by row
    for i in range(H):
        print(''.join(answer[i]))
    
    return

def main():
    # Generator function to iterate over input tokens
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word

    # Read input values for H, W, A, and B
    tokens = iterate_tokens()
    H = int(next(tokens))  # Height of the matrix
    W = int(next(tokens))  # Width of the matrix
    A = int(next(tokens))  # Column threshold for "0" and "1"
    B = int(next(tokens))  # Row threshold for "0" and "1"

    # Call the solve function with the input parameters
    solve(H, W, A, B)

# Entry point of the program
if __name__ == '__main__':
    main()
