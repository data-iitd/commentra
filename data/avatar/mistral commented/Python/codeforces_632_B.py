# This function is the entry point of the program
def main():
    # Read input from standard input
    input()

    # Parse input into a tuple of pairs, where each pair contains the score and the player of a piece
    pieces = tuple(zip(map(int, input().split()), input().split()))

    # Call the function to find Bob's maximum strength
    result = Bob_sMaxStrength(pieces)

    # Print the result
    print(result)

# This function calculates Bob's maximum strength based on the given pieces
def Bob_sMaxStrength(pieces):
    # Initialize variables to store the scores for players A and B
    p_score = s_score = p_max_score = s_max_score = 0

    # Iterate through each piece and update the scores accordingly
    for piece in pieces:
        # If the piece belongs to player A, add its score to p_score
        if piece[1] == 'A':
            p_score += piece[0]
            # Update p_max_score if the current p_score is greater
            if p_score > p_max_score:
                p_max_score = p_score
        # If the piece belongs to player B, subtract its score from p_score
        else:
            p_score -= piece[0]

    # Iterate through the pieces in reverse order and update the scores for player S
    for i in range(len(pieces)-1, -1, -1):
        # If the current piece belongs to player A, add its score to s_score
        if pieces[i][1] == 'A':
            s_score += pieces[i][0]
            # Update s_max_score if the current s_score is greater
            if s_score > s_max_score:
                s_max_score = s_score
        # If the current piece belongs to player B, subtract its score from s_score
        else:
            s_score -= pieces[i][0]

    # Return the maximum score between Bob's and Sally's scores
    if p_max_score > s_max_score:
        return p_max_score
    return s_max_score

# Run the main function if the script is executed directly
if __name__ == '__main__':
    main()
