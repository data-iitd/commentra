package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read input (the first input is ignored)
	var _ string
	fmt.Scanln(&_)

	// Read the second line of input
	var scoresLine string
	fmt.Scanln(&scoresLine)

	// Read the third line of input
	var charactersLine string
	fmt.Scanln(&charactersLine)

	// Create a slice of pieces where each piece is a struct of (score, character)
	pieces := make([]Piece, 0)
	scores := strings.Split(scoresLine, " ")
	for i, scoreStr := range scores {
		score, _ := strconv.Atoi(scoreStr)
		pieces = append(pieces, Piece{score: score, character: charactersLine[i]})
	}

	// Call the function to calculate Bob's maximum strength and print the result
	fmt.Println(BobsMaxStrength(pieces))
}

type Piece struct {
	score     int
	character rune
}

func BobsMaxStrength(pieces []Piece) int {
	// Initialize scores for player A and player B, and their maximum scores
	pScore := 0
	sScore := 0
	pMaxScore := 0
	sMaxScore := 0

	// Calculate maximum score for player A by iterating through pieces from the start
	for _, piece := range pieces {
		if piece.character == 'A' { // If the piece belongs to player A
			pScore += piece.score // Add the score of the piece to player A's score
			if pScore > pMaxScore { // Update maximum score if current score exceeds it
				pMaxScore = pScore
			}
		} else { // If the piece belongs to player B
			pScore -= piece.score // Subtract the score of the piece from player A's score
		}
	}

	// Calculate maximum score for player B by iterating through pieces from the end
	for i := len(pieces) - 1; i >= 0; i-- {
		if pieces[i].character == 'A' { // If the piece belongs to player A
			sScore += pieces[i].score // Add the score of the piece to player B's score
			if sScore > sMaxScore { // Update maximum score if current score exceeds it
				sMaxScore = sScore
			}
		} else { // If the piece belongs to player B
			sScore -= pieces[i].score // Subtract the score of the piece from player B's score
		}
	}

	// Return the maximum score between player A and player B
	if pMaxScore > sMaxScore {
		return pMaxScore
	}
	return sMaxScore
}

// <END-OF-CODE>
