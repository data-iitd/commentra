package main

import "fmt"

func main() {
	// Read input (the first input is ignored)
	fmt.Scanln()

	// Read the second line of input, split it into integers and corresponding characters,
	// and create a tuple of pieces where each piece is a tuple of (score, character)
	pieces := make([][2]int, 0)
	var score int
	var character byte
	fmt.Scanln(&score, &character)
	pieces = append(pieces, [2]int{score, int(character)})
	for fmt.Scanln(&score, &character); character != 'B'; fmt.Scanln(&score, &character) {
		pieces = append(pieces, [2]int{score, int(character)})
	}

	// Call the function to calculate Bob's maximum strength and return the result
	result := Bob_sMaxStrength(pieces)
	fmt.Println(result)
}

func Bob_sMaxStrength(pieces [][2]int) int {
	// Initialize scores for player A and player B, and their maximum scores
	pScore := 0
	sScore := 0
	pMaxScore := 0
	sMaxScore := 0
	for _, piece := range pieces {
		if piece[1] == 'B' {
			pScore += piece[0]
			if pScore > pMaxScore {
				pMaxScore = pScore
			}
		}
	}

	// Calculate maximum score for player A by iterating through pieces from the start
	for _, piece := range pieces {
		if piece[1] == 'A' {
			pScore += piece[0]
			if pScore > pMaxScore {
				pMaxScore = pScore
			}
		} else {
			pScore -= piece[0]
		}
	}

	// Calculate maximum score for player B by iterating through pieces from the end
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

	// Return the maximum score between player A and player B
	if pMaxScore > sMaxScore {
		return pMaxScore
	}
	return sMaxScore
}

// 