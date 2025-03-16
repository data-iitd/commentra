
func main() {
	// Take input from the user
	fmt.Scanln()
	// Process the input to get a tuple of (value, type) pairs for each piece
	pieces := tuple(zip(map(int, strings.Split(fmt.Scanln(), " ")), fmt.Scanln()))
	// Call the Bob_sMaxStrength function with the processed pieces and return its result
	return Bob_sMaxStrength(pieces)
}

func Bob_sMaxStrength(pieces [][]int) int {
	// Initialize scores for both ends and their maximum scores
	pScore := sScore := pMaxScore := sMaxScore := sum(piece[0] for piece in pieces if piece[1] == 'B')

	// Calculate the score from the front (left to right)
	for piece := range pieces {
		if pieces[piece][1] == 'A' {
			pScore += pieces[piece][0]
			if pScore > pMaxScore {
				pMaxScore = pScore
			}
		} else {
			pScore -= pieces[piece][0]
		}
	}

	// Calculate the score from the back (right to left)
	for i := len(pieces) - 1; i >= 0; i-- {
		if pieces[i][1] == 'A' {
			sScore += pieces[i][0]
			if sScore > sMaxScore {
				sMaxScore = sScore
			}
		} else {
			sScore -= pieces[i][0]
		}
	}

	// Return the maximum score between the two ends
	if pMaxScore > sMaxScore {
		return pMaxScore
	}
	return sMaxScore
}

func sum(values ...int) int {
	total := 0
	for _, value := range values {
		total += value
	}
	return total
}

func tuple(values ...[]int) [][]int {
	return values
}

func zip(values1, values2 []int) [][]int {
	result := make([][]int, len(values1))
	for i := range values1 {
		result[i] = []int{values1[i], values2[i]}
	}
	return result
}

func map(f func(int) int, values []int) []int {
	result := make([]int, len(values))
	for i := range values {
		result[i] = f(values[i])
	}
	return result
}

func main() {
	// Call the main function and print its result
	fmt.Println(main())
}

