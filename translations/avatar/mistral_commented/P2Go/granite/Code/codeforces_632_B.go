
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
	input()

	// Parse input into a tuple of pairs, where each pair contains the score and the player of a piece
	pieces := tuple(zip(map(int, input().split()), input().split()))

	// Call the function to find Bob's maximum strength
	result := Bob_sMaxStrength(pieces)

	// Print the result
	fmt.Println(result)
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

// This function reads input from standard input and returns it as a string
func input() string {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

// This function converts a string to an integer
func atoi(str string) int {
	result, _ := strconv.Atoi(str)
	return result
}

// This function converts a string to a slice of integers
func atois(str string) []int {
	result := make([]int, 0)
	for _, s := range strings.Split(str, " ") {
		result = append(result, atoi(s))
	}
	return result
}

// This function converts a slice of integers to a slice of pairs
func zip(a []int, b []string) [][2]int {
	result := make([][2]int, 0)
	for i, s := range b {
		result = append(result, [2]int{a[i], atoi(s)})
	}
	return result
}

// This function converts a slice of pairs to a tuple
func tuple(a [][2]int) [][2]int {
	return a
}

// This function converts a tuple to a slice of pairs
func untuple(a [][2]int) [][2]int {
	return a
}

// This function converts a slice of pairs to a slice of integers
func unzip1(a [][2]int) []int {
	result := make([]int, 0)
	for _, pair := range a {
		result = append(result, pair[0])
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip2(a [][2]int) []string {
	result := make([]string, 0)
	for _, pair := range a {
		result = append(result, strconv.Itoa(pair[1]))
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip(a [][2]int) ([]int, []string) {
	return unzip1(a), unzip2(a)
}

// This function converts a slice of strings to a slice of pairs
func zip(a []int, b []string) [][2]int {
	result := make([][2]int, 0)
	for i, s := range b {
		result = append(result, [2]int{a[i], atoi(s)})
	}
	return result
}

// This function converts a slice of pairs to a tuple
func tuple(a [][2]int) [][2]int {
	return a
}

// This function converts a tuple to a slice of pairs
func untuple(a [][2]int) [][2]int {
	return a
}

// This function converts a slice of pairs to a slice of integers
func unzip1(a [][2]int) []int {
	result := make([]int, 0)
	for _, pair := range a {
		result = append(result, pair[0])
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip2(a [][2]int) []string {
	result := make([]string, 0)
	for _, pair := range a {
		result = append(result, strconv.Itoa(pair[1]))
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip(a [][2]int) ([]int, []string) {
	return unzip1(a), unzip2(a)
}

// This function converts a slice of strings to a slice of pairs
func zip(a []int, b []string) [][2]int {
	result := make([][2]int, 0)
	for i, s := range b {
		result = append(result, [2]int{a[i], atoi(s)})
	}
	return result
}

// This function converts a slice of pairs to a tuple
func tuple(a [][2]int) [][2]int {
	return a
}

// This function converts a tuple to a slice of pairs
func untuple(a [][2]int) [][2]int {
	return a
}

// This function converts a slice of pairs to a slice of integers
func unzip1(a [][2]int) []int {
	result := make([]int, 0)
	for _, pair := range a {
		result = append(result, pair[0])
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip2(a [][2]int) []string {
	result := make([]string, 0)
	for _, pair := range a {
		result = append(result, strconv.Itoa(pair[1]))
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip(a [][2]int) ([]int, []string) {
	return unzip1(a), unzip2(a)
}

// This function converts a slice of strings to a slice of pairs
func zip(a []int, b []string) [][2]int {
	result := make([][2]int, 0)
	for i, s := range b {
		result = append(result, [2]int{a[i], atoi(s)})
	}
	return result
}

// This function converts a slice of pairs to a tuple
func tuple(a [][2]int) [][2]int {
	return a
}

// This function converts a tuple to a slice of pairs
func untuple(a [][2]int) [][2]int {
	return a
}

// This function converts a slice of pairs to a slice of integers
func unzip1(a [][2]int) []int {
	result := make([]int, 0)
	for _, pair := range a {
		result = append(result, pair[0])
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip2(a [][2]int) []string {
	result := make([]string, 0)
	for _, pair := range a {
		result = append(result, strconv.Itoa(pair[1]))
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip(a [][2]int) ([]int, []string) {
	return unzip1(a), unzip2(a)
}

// This function converts a slice of strings to a slice of pairs
func zip(a []int, b []string) [][2]int {
	result := make([][2]int, 0)
	for i, s := range b {
		result = append(result, [2]int{a[i], atoi(s)})
	}
	return result
}

// This function converts a slice of pairs to a tuple
func tuple(a [][2]int) [][2]int {
	return a
}

// This function converts a tuple to a slice of pairs
func untuple(a [][2]int) [][2]int {
	return a
}

// This function converts a slice of pairs to a slice of integers
func unzip1(a [][2]int) []int {
	result := make([]int, 0)
	for _, pair := range a {
		result = append(result, pair[0])
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip2(a [][2]int) []string {
	result := make([]string, 0)
	for _, pair := range a {
		result = append(result, strconv.Itoa(pair[1]))
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip(a [][2]int) ([]int, []string) {
	return unzip1(a), unzip2(a)
}

// This function converts a slice of strings to a slice of pairs
func zip(a []int, b []string) [][2]int {
	result := make([][2]int, 0)
	for i, s := range b {
		result = append(result, [2]int{a[i], atoi(s)})
	}
	return result
}

// This function converts a slice of pairs to a tuple
func tuple(a [][2]int) [][2]int {
	return a
}

// This function converts a tuple to a slice of pairs
func untuple(a [][2]int) [][2]int {
	return a
}

// This function converts a slice of pairs to a slice of integers
func unzip1(a [][2]int) []int {
	result := make([]int, 0)
	for _, pair := range a {
		result = append(result, pair[0])
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip2(a [][2]int) []string {
	result := make([]string, 0)
	for _, pair := range a {
		result = append(result, strconv.Itoa(pair[1]))
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip(a [][2]int) ([]int, []string) {
	return unzip1(a), unzip2(a)
}

// This function converts a slice of strings to a slice of pairs
func zip(a []int, b []string) [][2]int {
	result := make([][2]int, 0)
	for i, s := range b {
		result = append(result, [2]int{a[i], atoi(s)})
	}
	return result
}

// This function converts a slice of pairs to a tuple
func tuple(a [][2]int) [][2]int {
	return a
}

// This function converts a tuple to a slice of pairs
func untuple(a [][2]int) [][2]int {
	return a
}

// This function converts a slice of pairs to a slice of integers
func unzip1(a [][2]int) []int {
	result := make([]int, 0)
	for _, pair := range a {
		result = append(result, pair[0])
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip2(a [][2]int) []string {
	result := make([]string, 0)
	for _, pair := range a {
		result = append(result, strconv.Itoa(pair[1]))
	}
	return result
}

// This function converts a slice of pairs to a slice of strings
func unzip(a [][2]int) ([]int, []string) {
	return unzip1(a), unzip2(a)
}

// This function converts a slice of strings to a slice of pairs
func zip(a []int, b []string) [][2]int {
	result := make([][2]int, 0)
	for i, s := range b {
		result = append(result, [2]int{a[i], atoi(s)})
	}
	return result
}

// This function converts a slice of pairs to a tuple
func tuple(a [][2]int) [][2]int {
	return a
}

// This function converts a tuple to a slice of pairs
func untuple(a [][2]int) [][2]int {
	return a
}

// This function converts a slice of pairs to a slice of integers
func unzip1(a [][2]int) []int {
	result := make([]int, 0)
	for _, pair := range a {
		r