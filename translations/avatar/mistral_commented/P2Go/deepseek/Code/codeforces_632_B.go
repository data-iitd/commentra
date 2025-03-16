package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// This function is the entry point of the program
func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')

	// Parse input into a tuple of pairs, where each pair contains the score and the player of a piece
	input, _ := reader.ReadString('\n')
	piecesInput := strings.Split(strings.TrimSpace(input), " ")
	scores := []int{}
	players := []string{}

	for _, piece := range piecesInput {
		parts := strings.Split(piece, ",")
		score, _ := strconv.Atoi(parts[0])
		player := parts[1]
		scores = append(scores, score)
		players = append(players, player)
	}

	// Call the function to find Bob's maximum strength
	result := Bob_sMaxStrength(scores, players)

	// Print the result
	fmt.Println(result)
}

// This function calculates Bob's maximum strength based on the given pieces
func Bob_sMaxStrength(scores []int, players []string) int {
	// Initialize variables to store the scores for players A and B
	p_score := 0
	s_score := 0
	p_max_score := 0
	s_max_score := 0

	// Iterate through each piece and update the scores accordingly
	for i := 0; i < len(scores); i++ {
		// If the piece belongs to player A, add its score to p_score
		if players[i] == "A" {
			p_score += scores[i]
			// Update p_max_score if the current p_score is greater
			if p_score > p_max_score {
				p_max_score = p_score
			}
		} else {
			// If the piece belongs to player B, subtract its score from p_score
			p_score -= scores[i]
		}
	}

	// Iterate through the pieces in reverse order and update the scores for player S
	for i := len(scores) - 1; i >= 0; i-- {
		// If the current piece belongs to player A, add its score to s_score
		if players[i] == "A" {
			s_score += scores[i]
			// Update s_max_score if the current s_score is greater
			if s_score > s_max_score {
				s_max_score = s_score
			}
		} else {
			// If the current piece belongs to player B, subtract its score from s_score
			s_score -= scores[i]
		}
	}

	// Return the maximum score between Bob's and Sally's scores
	if p_max_score > s_max_score {
		return p_max_score
	}
	return s_max_score
}

