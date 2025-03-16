
import sys

def main():
    # Read the input string S
    S = input()
    score = 0 # Initialize score to zero
    
    # Iterate through each character in the string S
    for i in range(len(S)):
        # Determine the character for'my' based on the index (even or odd)
        my = 'g' if i % 2 == 0 else 'p'
        
        # Get the character from the input string at the current index
        his = S[i]
        
        # Compare'my' and 'his' characters to update the score
        if my!= his:
            # Increment score if'my' is 'p', otherwise decrement
            score += 1 if my == 'p' else -1
    
    # Output the final score
    print(score)

if __name__ == "__main__":
    main()

