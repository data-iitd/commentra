package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type Card struct {
	left int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Reading the first line of input
	line, _ := reader.ReadString('\n')
	var n, k int
	fmt.Sscanf(line, "%d %d", &n, &k)

	cards := make([]Card, 26) // Creating a slice of size 26 to store the cards

	// Reading the sequence of cards
	s, _ := reader.ReadString('\n')
	for _, char := range s {
		cards[char-'A'].left++ // Incrementing the left counter of the corresponding card
	}

	ans := int64(0) // Initializing the answer variable to zero
	for i := 0; i < k; i++ { // Iterating through each query
		sort.Slice(cards, func(a, b int) bool {
			return cards[a].left > cards[b].left // Sorting in descending order of their left counters
		})

		change := min(cards[25].left, k-i) // Calculating the number of cards to be moved
		ans += int64(change * change)       // Adding the square of the number of cards moved to the answer
		cards[25].left -= change            // Decreasing the left counter of the highest card by the number of cards moved
		i += change - 1                      // Skipping the next i-1 cards as they will have the same left counter
	}

	fmt.Fprintln(writer, ans) // Writing the answer to the standard output
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
