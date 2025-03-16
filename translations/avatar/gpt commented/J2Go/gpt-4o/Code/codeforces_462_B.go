package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Card struct {
	left int // Count of letters left
}

type ByLeft []Card

func (a ByLeft) Len() int           { return len(a) }
func (a ByLeft) Less(i, j int) bool { return a[i].left < a[j].left }
func (a ByLeft) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

func main() {
	// Initialize BufferedReader to read input from standard input
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the first line of input and tokenize it to extract n and k
	var n, k int
	fmt.Fscan(reader, &n, &k)

	// Create a slice of Card to count occurrences of each letter
	cards := make([]Card, 26)

	// Read the string of cards and count the occurrences of each letter
	var s string
	fmt.Fscan(reader, &s)
	for _, char := range s {
		cards[char-'A'].left++ // Increment the count for the corresponding letter
	}

	ans := int64(0) // Variable to store the final answer

	// Perform k operations to maximize the score
	for i := 0; i < k; i++ {
		sort.Sort(ByLeft(cards)) // Sort the cards based on the count of letters

		// Determine the number of changes to make for the most frequent letter
		change := min(cards[25].left, k-i)
		ans += int64(change * change) // Update the answer with the square of changes

		// Decrease the count of the most frequent letter by the number of changes made
		cards[25].left -= change
		i += change - 1 // Adjust the loop counter based on changes made
	}

	// Output the final result
	fmt.Fprintln(writer, ans)
}

// Helper function to get the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
