
def main():
    # Take input from the user
    input()
    # Process the input to get a tuple of (value, type) pairs for each piece
    pieces = tuple(zip(map(int, input().split()), input()))
    # Call the Bob_sMaxStrength function with the processed pieces and return its result
    return Bob_sMaxStrength(pieces)

def Bob_sMaxStrength(pieces):
    # Initialize scores for both ends and their maximum scores
    pScore = sScore = pMaxScore = sMaxScore = sum(piece[0] for piece in pieces if piece[1] == 'B')
    
    # Calculate the score from the front (left to right)
    for piece in pieces:
        if piece[1] == 'A':
            pScore += piece[0]
            if pScore > pMaxScore:
                pMaxScore = pScore
        else:
            pScore -= piece[0]
    
    # Calculate the score from the back (right to left)
    for i in range(len(pieces) - 1, -1, -1):
        if pieces[i][1] == 'A':
            sScore += pieces[i][0]
            if sScore > sMaxScore:
                sMaxScore = sScore
        else:
            sScore -= pieces[i][0]
    
    # Return the maximum score between the two ends
    if pMaxScore > sMaxScore:
        return pMaxScore
    return sMaxScore

if __name__ == '__main__':
    # Call the main function and print its result
    print(main())

