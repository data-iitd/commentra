package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take input from the user
	var n int
	fmt.Scan(&n) // Read the number of pieces
	var pieces []struct {
		value int
		typ   rune
	}

	// Read the values and types
	valuesInput := make([]string, n)
	typesInput := make([]rune, n)
	fmt.Scan(&valuesInput)
	for i := 0; i < n; i++ {
		value, _ := strconv.Atoi(valuesInput[i])
		pieces = append(pieces, struct {
			value int
			typ   rune
		}{value: value, typ: 'B'}) // Default to 'B'
	}
	fmt.Scan(&typesInput)

	for i := 0; i < n; i++ {
		pieces[i].typ = typesInput[i]
	}

	// Call the Bob_sMaxStrength function with the processed pieces and print its result
	fmt.Println(BobsMaxStrength(pieces))
}

func BobsMaxStrength(pieces []struct {
	value int
	typ   rune
}) int {
	// Initialize scores for both ends and their maximum scores
	pScore, sScore := 0, 0
	pMaxScore, sMaxScore := 0, 0

	// Calculate the initial score from 'B' pieces
	for _, piece := range pieces {
		if piece.typ == 'B' {
			pScore += piece.value
		}
	}
	pMaxScore = pScore

	// Calculate the score from the front (left to right)
	for _, piece := range pieces {
		if piece.typ == 'A' {
			pScore += piece.value
			if pScore > pMaxScore {
				pMaxScore = pScore
			}
		} else {
			pScore -= piece.value
		}
	}

	// Calculate the score from the back (right to left)
	for i := len(pieces) - 1; i >= 0; i-- {
		if pieces[i].typ == 'A' {
			sScore += pieces[i].value
			if sScore > sMaxScore {
				sMaxScore = sScore
			}
		} else {
			sScore -= pieces[i].value
		}
	}

	// Return the maximum score between the two ends
	if pMaxScore > sMaxScore {
		return pMaxScore
	}
	return sMaxScore
}

// <END-OF-CODE>
