def main():
    # Read input (the first input is ignored)
    input()
    
    # Read the second line of input, split it into integers and corresponding characters,
    # and create a tuple of pieces where each piece is a tuple of (score, character)
    pieces = tuple(zip(map(int, input().split()), input()))
    
    # Call the function to calculate Bob's maximum strength and return the result
    return Bob_sMaxStrength(pieces)

def Bob_sMaxStrength(pieces):
    # Initialize scores for player A and player B, and their maximum scores
    pScore = sScore = pMaxScore = sMaxScore = sum(piece[0] for piece in pieces if piece[1] == 'B')
    
    # Calculate maximum score for player A by iterating through pieces from the start
    for piece in pieces:
        if piece[1] == 'A':  # If the piece belongs to player A
            pScore += piece[0]  # Add the score of the piece to player A's score
            if pScore > pMaxScore:  # Update maximum score if current score exceeds it
                pMaxScore = pScore
        else:  # If the piece belongs to player B
            pScore -= piece[0]  # Subtract the score of the piece from player A's score

    # Calculate maximum score for player B by iterating through pieces from the end
    for i in range(len(pieces) - 1, -1, -1):
        if pieces[i][1] == 'A':  # If the piece belongs to player A
            sScore += pieces[i][0]  # Add the score of the piece to player B's score
            if sScore > sMaxScore:  # Update maximum score if current score exceeds it
                sMaxScore = sScore
        else:  # If the piece belongs to player B
            sScore -= pieces[i][0]  # Subtract the score of the piece from player B's score

    # Return the maximum score between player A and player B
    if pMaxScore > sMaxScore:
        return pMaxScore
    return sMaxScore

if __name__ == '__main__':
    # Execute the main function and print the result
    print(main())
