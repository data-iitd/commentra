# Import the sys module for reading input from standard input.
import sys

# Define a function named 'solve' that takes five arguments: S, T, A, B, and U.
def solve(S: str, T: str, A: int, B: int, U: str):

    # Check if S is equal to U. If yes, decrement A.
    if S == U:
        A -= 1

    # Check if T is equal to U. If yes, decrement B.
    if T == U:
        B -= 1

    # Print the updated values of A and B.
    print(A, B)

    # Return from the function.
    return

# Define a function named 'main' that doesn't take any arguments.
def main():

    # Define an inner function named 'iterate_tokens' that generates tokens from the standard input.
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word

    # Assign the next token to variables S, T, A, B, and U.
    S = next(iterate_tokens())
    T = next(iterate_tokens())
    A = int(next(iterate_tokens()))
    B = int(next(iterate_tokens()))
    U = next(iterate_tokens())

    # Call the 'solve' function with the assigned variables.
    solve(S, T, A, B, U)

# If the script is run as the main program, execute the 'main' function.
if __name__ == '__main__':
    main()
