package main

import (
	"fmt"
	"os"
)

func main() {
	// Read input from standard input
	var n int
	fmt.Scan(&n)

	// Parse input into a slice of pairs, where each pair contains the score and the player of a piece
	pieces := make([]struct {
		score int
		player string
	}, n)

	for i := 0; i < n; i++ {
		var score int
		var player string
		fmt.Scan(&score, &player)
		pieces[i] = struct {
			score int
			player string
		}{score, player}
	}

	// Call the function to find Bob's maximum strength
	result := BobMaxStrength(pieces)

	// Print the result
	fmt.Println(result)
}

// This function calculates Bob's maximum strength based on the given pieces
func BobMaxStrength(pieces []struct {
	score int
	player string
}) int {
	// Initialize variables to store the scores for players A and B
	pScore, sScore := 0, 0
	pMaxScore, sMaxScore := 0, 0

	// Iterate through each piece and update the scores accordingly
	for _, piece := range pieces {
		// If the piece belongs to player A, add its score to pScore
		if piece.player == "A" {
			pScore += piece.score
			// Update pMaxScore if the current pScore is greater
			if pScore > pMaxScore {
				pMaxScore = pScore
			}
		} else {
			// If the piece belongs to player B, subtract its score from pScore
			pScore -= piece.score
		}
	}

	// Iterate through the pieces in reverse order and update the scores for player S
	for i := len(pieces) - 1; i >= 0; i-- {
		piece := pieces[i]
		// If the current piece belongs to player A, add its score to sScore
		if piece.player == "A" {
			sScore += piece.score
			// Update sMaxScore if the current sScore is greater
			if sScore > sMaxScore {
				sMaxScore = sScore
			}
		} else {
			// If the current piece belongs to player B, subtract its score from sScore
			sScore -= piece.score
		}
	}

	// Return the maximum score between Bob's and Sally's scores
	if pMaxScore > sMaxScore {
		return pMaxScore
	}
	return sMaxScore
}

// <END-OF-CODE>
