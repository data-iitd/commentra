
import sys # Importing the sys module for input/output operations

# The main function reads input from the command line and writes output to the standard output
def main():
    S = sys.stdin.readline().strip() # Read the next string from the input
    score = 0 # Initialize the score to 0
    # Iterate through each character in the string S
    for i in range(len(S)):
        my = 'g' if i % 2 == 0 else 'p' # Determine the expected character based on the index
        his = S[i] # Get the character at the current index in S
        # Compare the expected character with the actual character and update the score
        if my!= his:
            score += 1 if my == 'p' else -1 # Update the score based on the expected character
    print(score) # Print the final score

# Call the main function to run the program
if __name__ == '__main__':
    main()

