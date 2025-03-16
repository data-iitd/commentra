package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input (the first input is ignored)
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')
	
	// Read the second line of input, split it into integers and corresponding characters,
	// and create a tuple of pieces where each piece is a tuple of (score, character)
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	scores := []int{}
	chars := []string{}
	for i, part := range parts {
		if i%2 == 0 {
			score, _ := strconv.Atoi(part)
			scores = append(scores, score)
		} else {
			chars = append(chars, part)
		}
	}
	
	// Call the function to calculate Bob's maximum strength and return the result
	fmt.Println(Bob_sMaxStrength(scores, chars))
}

func Bob_sMaxStrength(scores []int, chars []string) int {
	// Initialize scores for player A and player B, and their maximum scores
	pScore := 0
	sScore := 0
	pMaxScore := 0
	sMaxScore := 0
	
	// Calculate maximum score for player A by iterating through pieces from the start
	for i := 0; i < len(scores); i++ {
		if chars[i] == "B" {
			pScore += scores[i]
		} else {
			pScore -= scores[i]
		}
		if pScore > pMaxScore {
			pMaxScore = pScore
		}
	}
	
	// Calculate maximum score for player B by iterating through pieces from the end
	for i := len(scores) - 1; i >= 0; i-- {
		if chars[i] == "B" {
			sScore += scores[i]
		} else {
			sScore -= scores[i]
		}
		if sScore > sMaxScore {
			sMaxScore = sScore
		}
	}
	
	// Return the maximum score between player A and player B
	if pMaxScore > sMaxScore {
		return pMaxScore
	}
	return sMaxScore
}
