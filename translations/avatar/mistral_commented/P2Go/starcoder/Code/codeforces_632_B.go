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
	pieces := parseInput(reader)

	// Call the function to find Bob's maximum strength
	result := Bob_sMaxStrength(pieces)

	// Print the result
	fmt.Println(result)
}

// This function parses the input into a tuple of pairs, where each pair contains the score and the player of a piece
func parseInput(reader *bufio.Reader) [][2]int {
	// Read input from standard input
	input, _ := reader.ReadString('\n')

	// Split the input into a slice of strings
	input = strings.Split(input, " ")

	// Initialize a slice to store the parsed input
	pieces := make([][2]int, len(input)/2)

	// Iterate through the input and parse each pair into a tuple
	for i := 0; i < len(pieces); i++ {
		pieces[i][0], _ = strconv.Atoi(input[2*i])
		pieces[i][1] = input[2*i+1]
	}

	// Return the parsed input
	return pieces
}

// This function calculates Bob's maximum strength based on the given pieces
func Bob_sMaxStrength(pieces [][2]int) int {
	// Initialize variables to store the scores for players A and B
	p_score := s_score := p_max_score := s_max_score := 0

	// Iterate through each piece and update the scores accordingly
	for _, piece := range pieces {
		// If the piece belongs to player A, add its score to p_score
		if piece[1] == 'A' {
			p_score += piece[0]
			// Update p_max_score if the current p_score is greater
			if p_score > p_max_score {
				p_max_score = p_score
		}
		// If the piece belongs to player B, subtract its score from p_score
		else {
			p_score -= piece[0]
		}
	}

	// Iterate through the pieces in reverse order and update the scores for player S
	for i := len(pieces) - 1; i >= 0; i-- {
		// If the current piece belongs to player A, add its score to s_score
		if pieces[i][1] == 'A' {
			s_score += pieces[i][0]
			// Update s_max_score if the current s_score is greater
			if s_score > s_max_score {
				s_max_score = s_score
		}
		// If the current piece belongs to player B, subtract its score from s_score
		else {
			s_score -= pieces[i][0]
		}
	}

	// Return the maximum score between Bob's and Sally's scores
	if p_max_score > s_max_score {
		return p_max_score
	}
	return s_max_score
}

