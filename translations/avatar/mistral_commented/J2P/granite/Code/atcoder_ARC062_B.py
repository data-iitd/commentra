

import sys # Input stream to read input

def main():
    S = sys.stdin.readline().strip() # Read the input string
    score = 0 # Variable to store the score

    # Iterate through each character in the string
    for i in range(len(S)):
        my = 'g' if i % 2 == 0 else 'p' # Character representing my move
        his = S[i] # Character representing his move

        # Update the score based on the moves
        if my!= his:
            score += 1 if my == 'p' else -1

    # Print the score
    print(score)

if __name__ == '__main__':
    main()

These comments should provide a good understanding of what each part of the code does. Let me know if you need any further clarification!