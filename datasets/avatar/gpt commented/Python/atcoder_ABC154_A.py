import sys

def solve(S: str, T: str, A: int, B: int, U: str):
    # Check if the first string S matches the string U
    if S == U:
        A -= 1  # Decrement A if S matches U
    # Check if the second string T matches the string U
    if T == U:
        B -= 1  # Decrement B if T matches U
    # Print the final values of A and B
    print(A, B)
    return

def main():
    # Define a generator function to iterate over tokens from standard input
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word

    # Create a generator for tokens
    tokens = iterate_tokens()
    # Read the first string S from input
    S = next(tokens)
    # Read the second string T from input
    T = next(tokens)
    # Read the integer A from input and convert it to an integer
    A = int(next(tokens))
    # Read the integer B from input and convert it to an integer
    B = int(next(tokens))
    # Read the string U from input
    U = next(tokens)
    
    # Call the solve function with the read values
    solve(S, T, A, B, U)

# Entry point of the program
if __name__ == '__main__':
    main()
