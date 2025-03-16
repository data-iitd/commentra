// This function is the entry point of the program
func main() {
	// Read input from standard input
	fmt.Scanln()

	// Parse input into a slice of pairs, where each pair contains the score and the player of a piece
	pieces := make([][2]int, 0)
	for i := 0; i < 3; i++ {
		var score, player int
		fmt.Scan(&score, &player)
		pieces = append(pieces, [2]int{score, player})
	}

	// Call the function to find Bob's maximum strength
	result := Bob_sMaxStrength(pieces)

	// Print the result
	fmt.Println(result)
}

// This function calculates Bob's maximum strength based on the given pieces
func Bob_sMaxStrength(pieces [][2]int) int {
	// Initialize variables to store the scores for players A and B
	p_score, s_score, p_max_score, s_max_score := 0, 0, 0, 0

	// Iterate through each piece and update the scores accordingly
	for _, piece := range pieces {
		// If the piece belongs to player A, add its score to p_score
		if piece[1] == 1 {
			p_score += piece[0]
			// Update p_max_score if the current p_score is greater
			if p_score > p_max_score {
				p_max_score = p_score
			}
		} else {
			// If the piece belongs to player B, subtract its score from p_score
			p_score -= piece[0]
		}
	}

	// Iterate through the pieces in reverse order and update the scores for player S
	for i := len(pieces) - 1; i >= 0; i-- {
		// If the current piece belongs to player A, add its score to s_score
		if pieces[i][1] == 1 {
			s_score += pieces[i][0]
			// Update s_max_score if the current s_score is greater
			if s_score > s_max_score {
				s_max_score = s_score
			}
		} else {
			// If the current piece belongs to player B, subtract its score from s_score
			s_score -= pieces[i][0]
		}
	}

	// Return the maximum score between Bob's and Sally's scores
	if p_max_score > s_max_score {
		return p_max_score
	}
	return s_max_score
}

// Run the main function if the script is executed directly
func init() {
	if len(os.Args) == 1 {
		main()
	}
}

