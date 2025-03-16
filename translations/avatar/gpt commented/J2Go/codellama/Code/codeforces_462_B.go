package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Initialize BufferedReader to read input from standard input
	f := bufio.NewReader(os.Stdin)

	// Initialize PrintWriter to output results to standard output
	out := bufio.NewWriter(os.Stdout)

	// Read the first line of input and tokenize it to extract n and k
	st := strings.Split(f.ReadString('\n'), " ")
	n, _ := strconv.Atoi(st[0]) // Number of cards
	k, _ := strconv.Atoi(st[1]) // Maximum number of changes allowed

	// Create an array of c462b objects to count occurrences of each letter
	cards := make([]c462b, 26)
	for i := 0; i < 26; i++ {
		cards[i] = c462b{left: 0} // Initialize each card
	}

	// Read the string of cards and count the occurrences of each letter
	s := f.ReadString('\n')
	for t := 0; t < n; t++ {
		cards[s[t]-'A'].left++ // Increment the count for the corresponding letter
	}

	ans := 0 // Variable to store the final answer

	// Perform k operations to maximize the score
	for i := 0; i < k; i++ {
		sort.Slice(cards, func(i, j int) bool {
			return cards[i].left < cards[j].left
		}) // Sort the cards based on the count of letters

		// Determine the number of changes to make for the most frequent letter
		change := int(math.Min(float64(cards[25].left), float64(k-i)))
		ans += change * change // Update the answer with the square of changes

		// Decrease the count of the most frequent letter by the number of changes made
		cards[25].left -= change
		i += change - 1 // Adjust the loop counter based on changes made
	}

	// Output the final result
	fmt.Fprintln(out, ans)
	out.Flush() // Close the output stream
}

// Class to represent each card and implement Comparable for sorting
type c462b struct {
	left int
}

// Compare based on the count of letters
func (c c462b) Less(o interface{}) bool {
	return c.left < o.(c462b).left
}

