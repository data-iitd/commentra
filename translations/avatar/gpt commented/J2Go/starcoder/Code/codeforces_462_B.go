package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Class to represent each card and implement Comparable for sorting
type c462b struct {
	left int
}

// Function to read input from stdin
func readInput(reader *bufio.Reader) (n int, k int, s string) {
	// Read the first line of input and tokenize it to extract n and k
	line, _ := reader.ReadString('\n')
	tokens := strings.Split(line, " ")
	n, _ = strconv.Atoi(tokens[0])
	k, _ = strconv.Atoi(tokens[1])

	// Read the string of cards
	s = reader.ReadString('\n')
	s = s[:len(s)-1] // Remove the trailing newline character

	return
}

// Function to sort the cards based on the count of letters
func sortCards(cards []c462b) {
	sort.Slice(cards, func(i, j int) bool {
		return cards[i].left < cards[j].left
	})
}

// Function to perform k operations to maximize the score
func maximizeScore(cards []c462b, k int) (ans int) {
	sortCards(cards) // Sort the cards based on the count of letters

	// Perform k operations to maximize the score
	for i := 0; i < k; i++ {
		change := min(cards[25].left, k-i) // Determine the number of changes to make for the most frequent letter
		ans += change * change            // Update the answer with the square of changes
		cards[25].left -= change           // Decrease the count of the most frequent letter by the number of changes made
		i += change - 1                   // Adjust the loop counter based on changes made
	}

	return
}

// Function to find the minimum of two numbers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Function to print output to stdout
func printOutput(writer *bufio.Writer, ans int) {
	writer.WriteString(fmt.Sprintf("%d\n", ans))
}

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	n, k, s := readInput(reader)

	// Create an array of c462b objects to count occurrences of each letter
	cards := make([]c462b, 26)
	for i := 0; i < 26; i++ {
		cards[i] = c462b{} // Initialize each card
	}

	// Count the occurrences of each letter
	for _, c := range s {
		cards[c-'A'].left++ // Increment the count for the corresponding letter
	}

	// Perform k operations to maximize the score
	ans := maximizeScore(cards, k)

	// Print output to stdout
	writer := bufio.NewWriter(os.Stdout)
	printOutput(writer, ans)
	writer.Flush()
}

