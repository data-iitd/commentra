# Import the sys module for reading input from standard input.
import sys

# Define a function named 'solve' that takes four integer arguments: H, W, A, and B.
def solve(H: int, W: int, A: int, B: int):

    # Initialize a 2D list named 'answer' of size H x W with all elements set to the string "0".
    answer = [["0"] * W for _ in range(H)]

    # Iterate through each row 'i' in the range of H.
    for i in range(H):
        # Iterate through each column 'j' in the range of W.
        for j in range(W):
            # Set the value of the cell 'answer[i][j]' based on the conditions.
            if i < B:
                if j < A:
                    answer[i][j] = "0"
                else:
                    answer[i][j] = "1"
            else:
                if j < A:
                    answer[i][j] = "1"
                else:
                    answer[i][j] = "0"

    # Iterate through each row 'i' in the range of H and print its elements joined by an empty string.
    for i in range(H):
        print(''.join(answer[i]))

# Define a function named 'main' that does not take any arguments.
def main():

    # Define an inner function named 'iterate_tokens' that reads input from standard input and yields each token as a string.
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word

    # Read the input tokens and assign them to the variables H, W, A, and B.
    tokens = iterate_tokens()
    H = int(next(tokens))
    W = int(next(tokens))
    A = int(next(tokens))
    B = int(next(tokens))

    # Call the 'solve' function with the given input.
    solve(H, W, A, B)

# If the script is run as the main program, call the 'main' function.
if __name__ == '__main__':
    main()
